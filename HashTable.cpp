#include <cmath>
#include <iostream>

using namespace std;

class HashTable

{
    int tsize; // size of hash table = no. of indices
    int n; // no. of elements to be hashed = no. of keys
    int *arr; // hashtable array. indices of array, values stored at arr[index]
    int flag;


public:

    HashTable(int tablesize)
    {
        tsize = tablesize;
        arr = new int[tsize]; // all elements have no default value
        n = 0;
        flag = 0;


        // initialise default value of 0 for all array elements

        for (int i = 0; i < tsize; i++)
        {
            arr[i] = 0;
        }    
    }

    /*
    Use open addressing with quadratic probing!
    Use an array data structure. When it gets too full (load factor>0.8), make a new array of new size
    */

    int hash(int key, int size)
    {
        // h(k) = k % size of table
        return key%size;
    }

    // helper functions for resizer()
    bool isPrime(int a)
    {
        if (a <= 1)
        return false;

        // Check divisibility from 2 to a-1
        for (int i = 2; i < a; i++)
            if (a % i == 0)
                return false;
        return true;
    }

    int nextPrimeFinder(int a)
    {
        // keep checking successor number if it's prime
        while(!isPrime(a))
        {
            a++; // check next number (updation)
        }
        // exits loop only when the number we found is not prime
        return a;
    }

    void resizer(int ogsize)
    {
        // store old array pointer, figure out size of new array (hashtable)
        int *oldArr = arr;
        int newsize = ogsize*2;

        if(!isPrime(newsize))
        {
            // not prime, so find the next prime number and update newsize
            newsize = nextPrimeFinder(newsize);
        }
       

        // create new array (hashtable) of this newsize
        arr = new int[newsize]; // create a new array with the new size

        // update tsize
        tsize = newsize;

        // initialise all new array elements to zero
        for (int i = 0; i < tsize; i++)
        {
            arr[i] = 0;
        }

        // rehash all elements from old array to new array
        for (int i = 0; i < ogsize; i++) {

            if (oldArr[i] != 0 && oldArr[i]!=-999) { // only reinsert valid, unempty keys

                insert(oldArr[i]); // rehash and insert each key into the new array (still called arr)

                // initially was insert(arr[], oldArr[i]);

            }

        }

        // free up old array space
        delete[] oldArr;
    }

    void insert(int key)
    {
        //resize
        // if load factor exceeds 0.8
        // RESIZE CHECKER
        //cout << resizeChecker << "is the resize value" << endl;

        if(flag==1)
        {
            resizer(tsize); // input old/original array size
            flag = 0;
        }
       
        if ((float)(n+1) > 0.8 * tsize) // n+1 because we're inserting a new element but haven't yet incremented n
        {
            flag = 1;
        }

        int index = hash(key, tsize); // initial hash index
        int i = 1; // quadratic probing counter var


        // this while loop is only entered if the current position is non-empty
        while (arr[index] != 0 && arr[index]!=-999) // when it finds zero (empty slot) or deleted slot (-999) break out of loop
        {
            index = (key + (i * i)) % tsize; // quad probing formula
            i++;

            // avoid infinite loops. if program has probed more than the table size, break
            if (i >= tsize) {
                cout << "Max probing limit reached!" << key << endl;
                return;
            }
        }
        arr[index] = key; // insert (slot found)
        n++; // increment no. of elements var
    }

    void remove(int key) {

        int index = hash(key,tsize); // Initial hash index
        int i = 1; // loop var

        // Quadratic probing to find the key

        while (arr[index] != 0) {
            if (arr[index] == key)

            {
                arr[index] = -999; // mark slot as deleted -999 not 0 otherwise breaks probing sequence
                n--; // decrement no. of elements
                return;
            }

            index = (key + i * i) % tsize; // quadratic probing formula
            i++;

            if (i >= tsize) {
                cout << "Element not found" << endl;
                return;
            }

        }
        cout << "Element not found" << endl;
    }

    int search(int key)
    {
        int index = hash(key, tsize); // initial hash index
        int i = 1; // quadratic probing counter var

        // this while loop is only entered if the current position is non-empty
        while (arr[index] != 0) // when it finds zero, ie, an empty slot, break out of loop
        {
            if(arr[index] == key)
            {
                return index; // key found!
            }

            index = (key + (i * i)) % tsize; // quad probing formula
            i++;

            // avoid infinite loops. if program has probed more than the table size, break
            if (i >= tsize) {
                cout << "Max probing limit reached!" << key << endl;
                return -1; //error message
            }

        }

        return -1; // value found

    }

    void printTable()
    {

    // print array with conditional statements for _ (empty/deleted)
    for (int i = 0; i < tsize; i++) {

        if (arr[i] == -999 || arr[i] == 0) {

            cout << "- "; // empty or deleted slot

        } else {

            cout << arr[i] << " "; // filled slot

        }

    }

    cout << endl; // go to next line after printing full table

    }

};
