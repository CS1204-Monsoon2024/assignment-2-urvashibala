#include "HashTable.cpp"
class HashTable
{
    int tsize; // size of hash table = no. of indices
    int n; // no. of elements to be hashed = no. of keys
    int arr; // hashtable array. indices of array, values stored at arr[index]

    /*
    Use open addressing with quadratic probing!
    Use an array data structure. When it gets too full (load factor>0.8), make a new array of new size

    */

    int hash(int key)
    {
        // h(k) = k % size of table
        return key%tsize;
    }

    // helper functions for resizer()
    bool isPrime(int a)
    {
        if(a<0){return false;} // negative no.s can't be prime
        for(int i = 2; i<sqrt(a); i++) // only check till root n
        {
            if(a%i==0)
            {
                // then not prime
                return false;
            }
        }
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

       void resizer()
    {

        /**
         * threshold of α = 0.8, beyond which the table resizes to approximately double its
        current size. When resizing, remember to rehash all existing keys into the new table of larger
        size to maintain consistency.
        */

       // FINISH THIS FUNCTION
    }


    void insert(T, int key, int value)
    {
        // check if load factor is reached yet
        // must be n/tsize >= 0.8 => n>=0.8*tsize
        if(n>=0.8*tsize)
        {
            // if load factor (alpha) is over 0.8, then resize
            ht.resizer(arr.length); // passes current

        }

        int index = hash(key);
        bool alr_exists = false;


        if(T[index] == nullptr) // if index doesn't exist, ie, index==NULL (case 1)
        {
            // create new node at this index
            T[index] = new Node(key, value);
        }
        else // if index node exists
        {
            // open addressing with quadratic probing
            (while)            
           
        }
    }

    void remove(Node* T, int key, int value)
    { 
        int index = hash(key);
        bool alr_exists = false;

        if(T[index] == nullptr) // if index doesn't exist, ie, index==NULL (case 1)
        {
            // no node exists -- error case
            std::cout << "Element not found" << std::endl;

        }
        else // if index node exists
        {
            Node* current = T[index]; // temp traversal node "current"
            Node* prev = nullptr;  // node pointer to prev node

            //loop until last node (traverse LL)
            while(current->next!=nullptr)
            {
                // check if the current node's key is the one inputted
                if(current->key == key)
                {
                    // we've found the node key!
                    // mark it as alr exists
                    alr_exists = true;

                    // 3 cases. 
                    // case 1: we have to delete the head node
                    if(current->prev = nullptr)
                    {
                        T[index] = current->next; // we want to delete item at index. 
                        // we set it to the next node
                    }
                    else if(current->next = nullptr) // tail node to be deleted
                    {
                        current->prev = nullptr;
                    }
                    else
                    {
                        // specific middle node to be deleted
                        prev->next = current->next;
                    }

                    free(current); // ??? CHECK IF THIS MAKES SENSE

                }
                // loop updation
                current = current->next;
            }
            if(alr_exists==false)
            {
                // no such node exists -- error case
                std::cout << "Element not found" << std::endl;
            }

        }
    }

    void search()
    {

    }

printTable()

# hash f = key mod the size

int main() {
    int initialSize = 7; 
    HashTable ht(initialSize);

    // Example test case
    ht.insert(1);
    ht.printTable();
    ht.insert(6);
    ht.printTable();
    ht.insert(15);
    ht.printTable(); 
    ht.insert(25);
    ht.printTable();
    ht.remove(15);
    ht.printTable();
    ht.insert(29);  
    ht.printTable(); 

    int find = ht.search(22);
    std::cout << "Found at:" << find << std::endl;

    return 0;
}
} // end of class -- why error
