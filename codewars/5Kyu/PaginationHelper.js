// TODO: complete this object/class

// The constructor takes in an array of items and a integer indicating how many
// items fit within a single page
function PaginationHelper(collection, itemsPerPage){
    this.collection = collection;
    this.itemsPerPage = itemsPerPage;
}

// returns the number of items within the entire collection
PaginationHelper.prototype.itemCount = function() {
    return this.collection.length;
}

// returns the number of pages
PaginationHelper.prototype.pageCount = function() {
    let res = (this.collection.length/this.itemsPerPage)|0;
    return (this.collection.length%this.itemsPerPage==0?res:res+1);
}

// returns the number of items on the current page. page_index is zero based.
// this method should return -1 for pageIndex values that are out of range
PaginationHelper.prototype.pageItemCount = function(pageIndex) {
    let pos = (pageIndex+1)*this.itemsPerPage;
    if(pos <= this.collection.length){
        return this.itemsPerPage;
    }else{
        pos = pageIndex*this.itemsPerPage;
        if (pos <= this.collection.length)
            return this.collection.length - pos;
        else
            return -1;
    }
}

// determines what page an item is on. Zero based indexes
// this method should return -1 for itemIndex values that are out of range
PaginationHelper.prototype.pageIndex = function(itemIndex) {
    itemIndex = itemIndex+1;
    if(itemIndex < 1 || itemIndex > this.collection.length)
        return -1;
    if(itemIndex >= this.itemsPerPage){
        if(itemIndex%this.itemsPerPage > 0){
            return ((itemIndex/this.itemsPerPage)|0);
        }else{
            return ((itemIndex/this.itemsPerPage)|0) - 1;
        }
    }else{
        return 0;
    }
}

function main(){
    var helper = new PaginationHelper(['a','b','c','d','e','f','g','h','i'], 4);
    console.log(helper.pageCount()); //should == 2
    console.log(helper.itemCount()); //should == 6
    console.log(helper.pageItemCount(0)); //should == 4
    console.log(helper.pageItemCount(1)); // last page - should == 2
    console.log(helper.pageItemCount(2)); // should == 1 since the page is invalid
    console.log(helper.pageItemCount(3)); // should == -1 since the page is invalid

    // pageIndex takes an item index and returns the page that it belongs on
    console.log(helper.pageIndex(5)); //should == 1 (zero based index)
    console.log(helper.pageIndex(2)); //should == 0
    console.log(helper.pageIndex(8)); //should == 2
    console.log(helper.pageIndex(20)); //should == -1
    console.log(helper.pageIndex(-10)); //should == -1
}
main();