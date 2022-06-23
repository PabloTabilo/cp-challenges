library(readxl)
df <- read_excel("Downloads/GitHub/GIT_personal/cp-challenges/challenge_R/Excel.2022.54.xlsx",sheet = "BASE DE DATOS", col_types = c("date","text","text", "text","text", "text","numeric","text","text"))
df1 <- read_excel("Downloads/GitHub/GIT_personal/cp-challenges/challenge_R/Excel.2022.54.xlsx",sheet = "REGIONAL")

# First thing first
# check data types
head(df)
colnames(df)<-c("FECHA_DE_VENTA", "DEPARTAMENTO", "REGIONAL","MUNICIPIO",  
                "PUNTOS_DE_VENTA", "PRODUCTO", "VENTA","MES", "TIPO")

df$MES<-NULL
df$REGIONAL<-NULL

df$MES<-as.factor(format(df$FECHA_DE_VENTA,"%m"))
df$DEPARTAMENTO<-as.factor(df$DEPARTAMENTO)
df$MUNICIPIO<-as.factor(df$MUNICIPIO)
df$PUNTOS_DE_VENTA<-as.factor(df$PUNTOS_DE_VENTA)
df$TIPO<-as.factor(df$TIPO)
df$PRODUCTO<-as.factor(df$PRODUCTO)

summary(df)

#############
# Preguntas #

# Por medio de una tabla dinámica totalice la venta por mes del:
# 1. departamento
# 2. municipio
library(tidyverse)
library(ggplot2)

# Departamento
df %>% group_by(DEPARTAMENTO, MES) %>% summarize(total=sum(VENTA))

ggplot(df, aes(x=DEPARTAMENTO, y=VENTA, fill=MES)) + 
  geom_boxplot()

# Municipio
df_month_var1 <- function(df, mes, var1){
  df <- df[df$MES==mes,]
  principal_var1 <- df[,c(var1)]
  df <- df[order(-principal_var1),]
  row.names(df) <- NULL
  df$relative_max<-(principal_var1-min(principal_var1))/(max(principal_var1)-min(principal_var1))
  df$relative_total<-(principal_var1/sum(principal_var1))*100
  df$accum_total<-cumsum(df$relative_total)
  return(df)
}

x2 <- df %>% group_by(MUNICIPIO, MES) %>% summarize(total=sum(VENTA))
my_df_month_01 <- df_month_var1(as.data.frame(x2), "01", "total")
my_df_month_02 <- df_month_var1(as.data.frame(x2), "02", "total")
my_df_month_03 <- df_month_var1(as.data.frame(x2), "03", "total")

#res1<-as.data.frame(sort(table(df$MUNICIPIO), decreasing = T))
#colnames(res1)<-c("MUNI","Freq")
#total_res1 = sum(res1$Freq)
#res1$relativeFreq <- (res1$Freq / total_res1) * 100
#res1$acum <- cumsum(res1$relativeFreq)
#res1

ggplot() + 
  geom_point(data=my_df_month_01, aes(x=MUNICIPIO, y=total, color=MES))+
  geom_point(data=my_df_month_02, aes(x=MUNICIPIO, y=total, color=MES))+
  geom_point(data=my_df_month_03, aes(x=MUNICIPIO, y=total, color=MES))+
  theme(axis.text.x = element_text(angle = 90))

rm(x2)
#rm(res1)

# 3. Busque reginal de cada municipio
head(df1)
summary(df1)
df1$MUNICIPIO<-as.factor(df1$MUNICIPIO)
df1$REGIONAL<-as.factor(df1$REGIONAL)
summary(df1)
# mapear en un df todo >> {info de df1} e {df}
df$REGIONAL <- "EMPTY"
for(i in 1:nrow(df)){
  df[i,"REGIONAL"] <- as.character(df1[df[i,"MUNICIPIO"][[1]], "REGIONAL"][[1]])
}
df$REGIONAL <- as.factor(df$REGIONAL)
df %>% head() %>% print(width=Inf)

# 4. Por medio de una tabla dinámica sacar los promedios día hábil y festivo por municipio
x4 <- df %>% group_by(MUNICIPIO, MES, TIPO) %>% summarize(mean_venta=mean(VENTA), sd_venta=sd(VENTA))
x4
my_df_month_01<-df_month_var1(as.data.frame(x4),"01","mean_venta")

ggplot()+
  geom_point(data=my_df_month_01, aes(x = MUNICIPIO, y = mean_venta, color=TIPO))+
  theme(axis.text.x=element_text(angle=45, hjust=0.9))

my_df_month_02<-df_month_var1(as.data.frame(x4),"02","mean_venta")
ggplot()+
  geom_point(data=my_df_month_02, aes(x = MUNICIPIO, y = mean_venta, color=TIPO))+
  theme(axis.text.x=element_text(angle=45, hjust=0.9))

my_df_month_03<-df_month_var1(as.data.frame(x4),"03","mean_venta")
ggplot()+
  geom_point(data=my_df_month_03, aes(x = MUNICIPIO, y = mean_venta, color=TIPO))+
  theme(axis.text.x=element_text(angle=45, hjust=0.9))

rm(my_df_month_01)
rm(my_df_month_02)
rm(my_df_month_03)
rm(x4)
# 5. Identifique el pto de vta que presenta mayor venta por mes.
x5 <- df %>% group_by(PUNTOS_DE_VENTA, MES) %>% summarize(max_venta=max(VENTA))
x5

my_df_month<-df_month_var1(as.data.frame(x5),"01","max_venta")
head(my_df_month)
ggplot(my_df_month[1:31,], aes(x = reorder(PUNTOS_DE_VENTA, +max_venta), y = max_venta))+ 
  geom_bar(stat="identity", color='red',fill='red')+ 
  theme(axis.text.x=element_text(angle=45, hjust=0.9))

my_df_month<-df_month_var1(as.data.frame(x5),"02","max_venta")
head(my_df_month)
ggplot(my_df_month[1:47,], aes(x = reorder(PUNTOS_DE_VENTA, +max_venta), y = max_venta))+ 
  geom_bar(stat="identity", color='darkblue',fill='darkblue')+ 
  theme(axis.text.x=element_text(angle=45, hjust=0.9))

my_df_month<-df_month_var1(as.data.frame(x5),"03","max_venta")
head(my_df_month)
ggplot(my_df_month[1:32,], aes(x = reorder(PUNTOS_DE_VENTA, +max_venta), y = max_venta))+ 
  geom_bar(stat="identity", color='darkorange',fill='darkorange')+ 
  theme(axis.text.x=element_text(angle=45, hjust=0.9))

rm(my_df_month)
rm(x5)

