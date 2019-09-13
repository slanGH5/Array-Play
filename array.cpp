#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// FUNCTION DECLARATIONS ////////////////////////////////////////////////////////////////////////////////////////////

int locateMinimum( const string array[ ], int n );
int findLastOccurrence( const string array[ ], int n, string target );
int flipAround( string array[ ], int n );
bool hasNoDuplicates( const string array[ ], int  n );
void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize );
int shiftRight( string array[ ], int n, int amount, string placeholderToFillEmpties );
bool isInIncreasingOrder( const string array[ ], int  n );

// MAIN PROGRAM ////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    
    string pope[10] = {
        "1terror", "2x", "flappy", "2x", "Abacus", "Aape",
        "Zeke", "alrighty", "2x", "2x"
    };
    
    string yeet[4] = {
        "0topia", "yahoo", "89lol", "yahoo"
    };
    
    string whoa[7] = {
        "AI", "DL", "ML", "SL", "UL", "ML", "alrighty"
    };
    
    string test1[5] = {
        "5", "4", "3", "2", "1"
    };
    
    string test2[5] = {
        "20", "2", "3", "4", "5"
    };
    
    /*string results[6];
    int resultSize = 6;
    unionWithNoDuplicates(test1, 5, test2, 5, results, resultSize);
    for(int i=0; i<resultSize;i++){
        cout << results[i] << "  ";
    }
    cout << endl << "This is the resulting size of the array: " << resultSize << endl;
    */
    
    assert(locateMinimum(yeet, 3) == 0);
    assert(locateMinimum(yeet, 0) == -1);
    assert(locateMinimum(yeet, -1) == -1);
    assert(findLastOccurrence(yeet, 4, "yahoo") == 3);
    assert(findLastOccurrence(yeet, -1, "yahoo") == -1);
    assert(findLastOccurrence(yeet, 1, "yahoo") == -1);
    assert(findLastOccurrence(yeet, 0, "yahoo") == -1);
    assert(hasNoDuplicates(yeet, 4) == false);
    assert(hasNoDuplicates(yeet, 3) == true);
    assert(hasNoDuplicates(yeet, 2) == true);
    assert(hasNoDuplicates(yeet, 0) == true);
    assert(hasNoDuplicates(yeet, 1) == true);
    assert(hasNoDuplicates(yeet, -1) == false);
    assert(isInIncreasingOrder(yeet, 2) == true);
    assert(isInIncreasingOrder(yeet, 4) == false);
    assert(isInIncreasingOrder(yeet, -1) == false);
    assert(isInIncreasingOrder(yeet, 0) == true);
    
    assert(locateMinimum(pope, 10) == 0);
    assert(locateMinimum(pope, -1) == -1);
    assert(findLastOccurrence(pope, 10, "2x") == 9);
    assert(findLastOccurrence(pope, 9, "2x") == 8);
    assert(findLastOccurrence(pope, 1, "2x") == -1);
    assert(hasNoDuplicates(pope, 1) == true);
    assert(hasNoDuplicates(pope, 3) == true);
    assert(hasNoDuplicates(pope, 4) == false);
    assert(hasNoDuplicates(pope, -1) == false);
    assert(isInIncreasingOrder(pope, 3) == true);
    assert(isInIncreasingOrder(pope, 4) == false);
    assert(isInIncreasingOrder(pope, 5) == false);
    
    cout << "All the tests succeeded!" << endl;
    
        //CHECKING WITH ARRAY:YEET
    //assert(flipAround(yeet, 4) == 2);
    //assert(flipAround(yeet, 3) == 1);
    //assert(flipAround(yeet, -1) == -1);
    
    //assert(shiftRight(yeet, 4, 3, "bubble") == 1);
    //assert(shiftRight(yeet, 4, 0, "hello") == 4);
    //assert(shiftRight(yeet, 3, 1, "ok") == 2);
    //assert(shiftRight(yeet, 3, 2, "tea") == 1);
    //assert(shiftRight(yeet, -1, 0, "ah") == -1);
    //assert(shiftRight(yeet, 4, 5, "usb") == -1);
    
    /*
     string results[10];
     int resultSize = 10;
     unionWithNoDuplicates(pope, 10, yeet, 4, results, resultSize);
     for(int i=0; i<resultSize;i++){
        cout << results[i] <<endl;
     }
     cout << "This is the resulting size of the array: " << resultSize << endl;
    */
    
        //CHECKING WITH ARRAY:POPE
    //assert(flipAround(pope, 10) == 5);
    //assert(flipAround(pope, 3) == 1);
    //assert(flipAround(pope, -1) == -1);
    
    //assert(shiftRight(pope, 10, 4, "bubble") == 6);
    //assert(shiftRight(pope, 10, 9, "ok") == 1);
    //assert(shiftRight(pope, 5, 3, "tea") == 2);
    //assert(shiftRight(pope, -1, 0, "ah") == -1);
    //assert(shiftRight(pope, 0, 1, "usb") == -1);
    
    /*
     string results[12];
     int resultSize = 12;
     unionWithNoDuplicates(pope, 10, whoa, 7, results, resultSize);
     for(int i=0; i<resultSize;i++){
     cout << results[i] <<endl;
     }
     cout << "This is the resulting size of the array: " << resultSize << endl;
    */

    return(0);
}

// FUNCTION DEFINITIONS /////////////////////////////////////////////////////////////////////////////////////////////

//1. LOCATING MINIMUM ///////////////////////////////////////////////////////////////////////////////////////////////
int locateMinimum( const string array[ ], int n ){
    if (n <= 0)
        return(-1);
    
    int index = 0;
    for (int i = 0; i < n; i++){
        string test1 = array[i];  //have to initialize element of array as string to compare to each other
        string test2 = array[index];
        if (test1 < test2)
            index = i;
    }
        return(index);
}

//2. FINDING LAST OCCURENCE //////////////////////////////////////////////////////////////////////////////////////////
int findLastOccurrence( const string array[ ], int n, string target ){
    int index = -1;
    for (int i = 0; i < n; i++){
        if (array[i] == target)
            index = i;
    }
    if (n <= 0)
        index = -1;
    return(index);
}

//3. FLIP AROUND /////////////////////////////////////////////////////////////////////////////////////////////////////
int flipAround( string array[ ], int n ){

    for (int i = 0; i < n/2; i++){ //iterates until n/2 because you initialize the 'flip' from the first half of the array
        string temp = array[i];    //saves first element to a temporary variable
        array[i] = array[n-(i+1)]; //sets first element to the last element
        array[n-(i+1)] = temp;     //sets last element to the value of the temporary variable
    }
                                                /*cerr << "This is the flipped array"<< endl;
                                                for (int i=0; i<n; i++){
                                                        cerr << array[i] <<endl;
                                                }
                                                cerr << "This flipped " << n/2 << " time(s)." << endl;*/
    int flipped = 0;
    if (n <= 0)
        flipped = -1;
    else
        flipped = n/2;
    return(flipped);
}

//4. NO DUPLICATES //////////////////////////////////////////////////////////////////////////////////////////////////
bool hasNoDuplicates( const string array[ ], int  n ){
    if (n < 0)
        return false;
    
    for (int i = 0; i < n; i++){        //iterates through array from first element
        for (int k = i+1; k < n; k++){  //iterates through array from the second element
            if (array[i] == array[k]){
                return false;}
        }
    }
    return true;
}

//5. UNION WITH NO DUPLICATES ////////////////////////////////////////////////////////////////////////////////////////
void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize ){

    int indexForInsert = 0;           //index where values from array1[] and array2[] are inserted into resultingString[]
    int firstDupes = 0;
    resultingSize = 0;
    
    for (int i=0; i < n1; i++){                         //loop through array1[] first
        bool needToAdd = true;
        for (int k=0; k < resultingSize; k++){          //loop through new array
            if (array1[i] == resultingString[k]){       //if there are duplicates in array1[], don't add the duplicate to the new array
                needToAdd = false;
                firstDupes++;                           //count number of duplicates for later usage
            }
        }
        if (needToAdd){                                 //if element is not a duplicate, input the element into the new array
            resultingString[indexForInsert] = array1[i];
            indexForInsert++;
            resultingSize++;
            }
    }
    
    indexForInsert = n1-firstDupes;
    
    for (int i=0; i < n2; i++){                         //loop through array2[] and compare to values in new array for duplicates
        bool needToAdd = true;
        for (int k = 0; k < resultingSize; k++){
            if (array2[i] == resultingString[k]){       //if element is found already in new array, set needToAdd to false so you don't add it
                needToAdd = false;}
        }
        
        if (needToAdd){                                 //if element is not a duplicate, input the element into the new array
            resultingString[indexForInsert] = array2[i];
            indexForInsert++;
            resultingSize++;
        }
    }
    
    if (n1 <= 0 || n2 <= 0){
        resultingSize = -1;
    }
}


//6. SHIFT RIGHT ///////////////////////////////////////////////////////////////////////////////////////////////////
int shiftRight( string array[ ], int n, int amount, string placeholderToFillEmpties ){
    if (n < 0){
        return -1;
    }
    int keep = n - amount;
    
    if (keep < 0){
        return -1;
    }
    for (int i = n-1; i >= amount; i--){      //fill the array with kept values
        array[i] = array[i-amount];
    }
    for (int i = 0; i < amount; i++){
        array[i] = placeholderToFillEmpties;  //fill the array with new placeholders (from the beginning)
    }
                                                    /*cerr << "This is the new array: "<< endl;
                                                    for (int i = 0; i < n; i++){
                                                        cerr << array[i] << endl;
                                                            }
                                                        cerr << keep << endl;*/
    return keep;
}
//7. INCREASING ORDER ////////////////////////////////////////////////////////////////////////////////////////////
bool isInIncreasingOrder( const string array[ ], int  n ){

    if (n < 0)
        return false;
    
    for (int i = 0; i < n-1; i++){
        string test1 = array[i];      //initialize elements as string to compare them
        string test2 = array[i+1];
        if (test1 >= test2)
            return false;
    }
    return true;
}
