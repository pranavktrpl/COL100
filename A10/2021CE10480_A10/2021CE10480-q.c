#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

// create a node with data as x
struct Node* create_node(int x) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}

// delete the node at `ptr` and free its memory
void delete_node(struct Node* ptr) {
    free(ptr);
}

// ------------------------------ Node struct definition ends here ------------------------------

// Use this to operate on the list, this will always point at the head of the list.
struct Node* PythonListHead = NULL;


// prints the list in space seperated format
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


// Add an item to the end of the list
void append(int x) {
    if(PythonListHead == NULL){
        PythonListHead = create_node(x);
    }else{
        struct Node* curr = PythonListHead;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = create_node(x);
    }
}


// Return the number of elements in the list
int len() {
    // your code goes here
    struct Node* curr = PythonListHead;
    int counter = 0;
    while(curr != NULL){
        counter++;
        curr = curr->next;
    }
    return counter;
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    if( len()-1 >= position ){
        struct Node* new_ptr = create_node(x);
        struct Node* curr = PythonListHead;
        if(position>0){
            for(int i=0; i<=position-2; i++){
                curr = (*curr).next;
            }
            struct Node* old_ptr = curr->next;
            curr->next = new_ptr;
            new_ptr->next = old_ptr;
        }
        else if(position==0){
            (*new_ptr).next = PythonListHead;
            PythonListHead = new_ptr; 
        }
    }
}


// Remove the item at the end of the list
void pop() {
    if(len()>0){
        struct Node* curr = PythonListHead;
        while((curr->next)->next!=NULL){
            curr = curr->next;
        }
        struct Node* last = (curr->next);
        if(last->next == NULL){
            delete_node(last);
            curr->next = NULL;
        }
    }
}


// Remove all items from the list
void clear() {
    struct Node* curr = PythonListHead;
    struct Node* nxt;
    while(curr->next != NULL){
        nxt = curr->next;
        // printf("%u\n",curr);
        delete_node(curr);
        curr = nxt;
    }
    PythonListHead = NULL;
    delete_node(curr);
}


// Return the number of times x appears in the list.
int count(int x) {
    // your code goes here
    struct Node* curr = PythonListHead;
    int counter = 0;
    while(curr != NULL){
        if(curr->data == x){
            counter++;
        }
        curr = curr->next;
    }
    return counter;
}


// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* prev = NULL;
    struct Node* curr = PythonListHead;
    struct Node* nxt = NULL;
    while (curr != NULL) {
        // Store next
        nxt = curr->next;
 
        // Reverse current node's pointer
        curr->next = prev;
 
        // Move pointers one position ahead.
        prev = curr;
        curr = nxt;
    }
    PythonListHead = prev;
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    struct Node* curr = PythonListHead;
    
    //get pointer to the position node
    for(int i=0;i<=position-1;i++){
        //printf("%d\n",(*curr).data);
        curr = curr->next;
    }
    curr->data = x;
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    // your code goes here
    if(position<=len()-1){
        struct Node* curr = PythonListHead;
        
        //get pointer to the position node
        for(int i=0;i<=position-1;i++){
            //printf("%d\n",(*curr).data);
            curr = curr->next;
        }
        return curr->data;
    }else{
        return -1;
    }
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {                            // check for erase 0
    if(len()-1>=position){
        if(position>0){
            struct Node* prev = PythonListHead;
            //get pointer to the prev position node
            for(int i=0;i<=position-2;i++){
                //printf("%d\n",(*curr).data);
                prev = prev->next;
            }
            struct Node* curr = prev->next;
            struct Node* nxt = curr->next;
            delete_node(curr);
            prev->next = nxt;
        }else if(position==0){
            struct Node* curr = PythonListHead;
            PythonListHead = curr->next;
            delete_node(curr);
        }
    }
}


// Returns a the head of the newly formed Python List
// containing elements present in positions in the original List.
// Note: you have to create new Python List and return its head.
// Here positions is an array of size n.
// eg. if positions = [2, 3, 5], you need to return a newly formed list
// having nodes that were at position 2, 3 and 5 in the original list.
// if there is such a position that is not present in the original list, do nothing
// with that position.
struct Node* index_into(int *positions, int n) {
 // your code goes here
    struct Node* new_PythonListHead = NULL;
    struct Node* new_curr = NULL;

    int pos[n];
    for(int i=1;i<=n;i++){
        pos[i] = *positions;
        positions++;
    }    
        
    // //get pointer to the first position node
    // struct Node* curr = PythonListHead;
    // for(int i=0;i<=pos[1]-1;i++){
    //     //printf("%d\n",(*curr).data);
    //     curr = curr->next;
    // }

    // new_PythonListHead = curr;
    // new_curr = new_PythonListHead;

    for(int j=1;j<=n;j++){
        if(len()-1>=pos[j]){
            //get pointer to the given position node
            struct Node* curr = PythonListHead;
            for(int i=0;i<=pos[j]-1;i++){
                //printf("%d\n",(*curr).data);
                curr = curr->next;
            }
            if(new_PythonListHead!=NULL){
                int x = curr->data;
                new_curr->next = create_node(x);
                new_curr = new_curr->next;
            }else{
                int x = curr->data;
                new_PythonListHead = create_node(x);
                new_curr = new_PythonListHead;
                }
        }else{
            continue;
        }
    }
    if(new_curr!=NULL){
    new_curr->next = NULL;
    }

    return new_PythonListHead;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    if(position>0){
        if(len()-2>=position){
            
            struct Node* curr = PythonListHead;
            //get pointer to the node prev to position node
            for(int i=0;i<=position-2;i++){
                //printf("%d\n",(*curr).data);
                curr = curr->next;
            }
            //curr is pointing at position - 1

            struct Node* ptr_pos = curr->next;
            struct Node* ptr_Nxtpos = ptr_pos->next;
            struct Node* rem_list = ptr_Nxtpos->next;
            //make the prev to pos node hold pos+1 address
            //make pos hold pos+2 address
            //make the pos+1 address hold pos adress

            curr->next = ptr_Nxtpos;
            ptr_Nxtpos->next = ptr_pos;
            ptr_pos->next = rem_list;
        }
    }else if(position==0){
        if(len()>=2){
            //get pointer to the node prev to position node
            //curr is pointing at position - 1

            struct Node* ptr_pos = PythonListHead;
            struct Node* ptr_Nxtpos = ptr_pos->next;
            struct Node* rem_list = ptr_Nxtpos->next;
            //make the prev to pos node hold pos+1 address
            //make pos hold pos+2 address
            //make the pos+1 address hold pos adress

            PythonListHead = ptr_Nxtpos;
            ptr_Nxtpos->next = ptr_pos;
            ptr_pos->next = rem_list;
            
        }
    }
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    for(int i=1;i<=len()-1;i++){
        for(int j=0;j<=len()-2;j++){
            struct Node* curr = PythonListHead;
            //get pointer to the position node
            for(int k=0;k<=j-1;k++){
                //printf("%d\n",(*curr).data);
                curr = curr->next;
            }
            if((curr->data)>((curr->next)->data)){
                swap(j);
            }
            curr = curr->next;
        }
    }
}


// ----------------------- Driver program starts here -----------------------

int main(int argc, char const *argv[])
{
    int T; 
    scanf("%d", &T);

    char operation_type[20];
    int indices[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "append") == 0) {
            int x;
            scanf("%d", &x);
            append(x);
        } 

        if(strcmp(operation_type, "insert") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insert(pos, x);
        }

        if(strcmp(operation_type, "pop") == 0) {
            pop();
        }

        if(strcmp(operation_type, "clear") == 0) {
            clear();
        }

        if(strcmp(operation_type, "count") == 0) {
            int x;
            scanf("%d", &x);
            int cnt = count(x);
            printf("%d\n", cnt);
        }

        if(strcmp(operation_type, "reverse") == 0) {
            reverse();
        }

        if(strcmp(operation_type, "len") == 0) {
            int length = len();
            printf("%d\n", length);
        }

        if(strcmp(operation_type, "setitem") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            setitem(pos, x);
        }

        if(strcmp(operation_type, "getitem") == 0) {
            int pos;
            scanf("%d", &pos);
            int value = getitem(pos);
            printf("%d\n", value);
        }

        if(strcmp(operation_type, "print") == 0) {
            print_list(PythonListHead);
        }

        if(strcmp(operation_type, "erase") == 0) {
            int pos;
            scanf("%d", &pos);
            erase(pos);
        }

        if(strcmp(operation_type, "swap") == 0) {
            int pos;
            scanf("%d", &pos);
            swap(pos);
        }

        if(strcmp(operation_type, "index_into") == 0) {
            int n;
            scanf("%d", &n);
            for(int i=0;i<n;i++) scanf("%d", &indices[i]);
            struct Node* new_head = index_into(indices, n);
            print_list(new_head);
        }

        if(strcmp(operation_type, "sort") == 0) {
            sort();
        }
    }
}