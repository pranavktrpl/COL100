#include<stdio.h>
#include<stdlib.h>
#include <string.h>

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
}


// helper function that returns pointer to `Node` at `position`
// if there is no such position, it returns NULL
struct Node* get_node_at_pos(int position) {
    int pos = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        if(pos == position) return cur;
        pos++;
        cur = cur->next;
    }
    return NULL;
}


// Return the number of elements in the list
int len() {
    int length = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        length++;
        cur = cur->next;
    }
    return length;
}


// Add an item to the end of the list
void append(int x) {
    struct Node* cur = PythonListHead;
    if(cur == NULL) {
        // no list exists, we have to create one
        PythonListHead = create_node(x);
    }
    else {
        int pos = len() - 1;
        struct Node* last_node = get_node_at_pos(pos);
        last_node->next = create_node(x);
    }
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    int n = len();
    if(position >= n) return;
    struct Node* node_at_position = get_node_at_pos(position);
    // 2 cases now
    // if node_at_position is the first node
    if(position == 0) {
        struct Node* new_node = create_node(x);
        new_node->next = node_at_position;
        PythonListHead = new_node;
    }
    else { // node_at_position is not the first node
        struct Node* previous_node = get_node_at_pos(position-1);
        previous_node->next = create_node(x);
        previous_node->next->next = node_at_position;
    }
}


// Remove the item at the end of the list
void pop() {
    int n = len();
    if(n == 0) return;

    if(n == 1) {
        delete_node(PythonListHead);
        PythonListHead = NULL;
    }
    else {
        struct Node* second_last_node = get_node_at_pos(n-2);
        delete_node(second_last_node->next);
        second_last_node->next = NULL;
    }
}


// Remove all items from the list
void clear() {
    struct Node* cur = PythonListHead;
    PythonListHead = NULL;
    while(cur) {
        struct Node* next_node = cur->next;
        delete_node(cur);
        cur = next_node;
    }
}


// Return the number of times x appears in the list.
int count(int x) {
    struct Node* cur = PythonListHead;
    int cnt = 0;
    while(cur) {
        if(cur->data == x) cnt++;
        cur = cur->next;
    }
    return cnt;
}

struct Node* reverse_helper(struct Node* cur_node) {
    if(cur_node == NULL) return NULL;

    if(cur_node->next == NULL) {
        // this is the first node of the reversed list
        PythonListHead = cur_node;
        return cur_node;
    }

    // recursively solve for the next node
    struct Node* next_node = reverse_helper(cur_node->next);

    // set the next of next_node to cur_node
    next_node->next = cur_node;

    // also make the cur_node->next as NULL, since cur_node is the last node of the list
    cur_node->next = NULL;

    return cur_node;
}

// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* last_node = reverse_helper(PythonListHead);
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(node_at_pos) {
        node_at_pos->data = x;
    }
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(node_at_pos) {
        return node_at_pos->data;
    }
    else return -1;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(!node_at_pos) return;

    // 2 cases now
    // if node_at_pos is the first node
    if(node_at_pos == PythonListHead) {
        PythonListHead = PythonListHead->next;
        delete_node(node_at_pos);
    }
    else {
        struct Node* previous_node = get_node_at_pos(position-1);
        previous_node->next = node_at_pos->next;
        delete_node(node_at_pos);
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
    struct Node* new_list_head = NULL;
    struct Node* new_list_tail = NULL;
    for(int i=0;i<n;i++) {
        struct Node* node_at_pos = get_node_at_pos(positions[i]);

        if(!node_at_pos) continue;

        if(new_list_tail) {
            new_list_tail->next = create_node(node_at_pos->data);
            new_list_tail = new_list_tail->next;
        }
        else {
            new_list_head = create_node(node_at_pos->data);
            new_list_tail = new_list_head;
        }
    }
    return new_list_head;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    struct Node* next_node = get_node_at_pos(position+1);
    if(!node_at_pos || !next_node) return;

    // 2 cases 
    if(node_at_pos == PythonListHead) {
        PythonListHead = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
    else {
        struct Node* prev_node = get_node_at_pos(position-1);
        prev_node->next = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    int n = len();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            int x = get_node_at_pos(j)->data;
            int y = get_node_at_pos(j+1)->data;
            if(x > y) swap(j);
        }
    }
}


// ----------------------- Driver program starts here -----------------------

// int main(int argc, char const *argv[])
// {
//     int T; 
//     scanf("%d", &T);

//     char operation_type[20];
//     int indices[100];

//     while(T--) {
//         scanf("%s", operation_type);

//         if(strcmp(operation_type, "append") == 0) {
//             int x;
//             scanf("%d", &x);
//             append(x);
//         } 

//         if(strcmp(operation_type, "insert") == 0) {
//             int pos, x;
//             scanf("%d %d", &pos, &x);
//             insert(pos, x);
//         }

//         if(strcmp(operation_type, "pop") == 0) {
//             pop();
//         }

//         if(strcmp(operation_type, "clear") == 0) {
//             clear();
//         }

//         if(strcmp(operation_type, "count") == 0) {
//             int x;
//             scanf("%d", &x);
//             int cnt = count(x);
//             printf("%d\n", cnt);
//         }

//         if(strcmp(operation_type, "reverse") == 0) {
//             reverse();
//         }

//         if(strcmp(operation_type, "len") == 0) {
//             int length = len();
//             printf("%d\n", length);
//         }

//         if(strcmp(operation_type, "setitem") == 0) {
//             int pos, x;
//             scanf("%d %d", &pos, &x);
//             setitem(pos, x);
//         }

//         if(strcmp(operation_type, "getitem") == 0) {
//             int pos;
//             scanf("%d", &pos);
//             int value = getitem(pos);
//             printf("%d\n", value);
//         }

//         if(strcmp(operation_type, "print") == 0) {
//             print_list(PythonListHead);
//         }

//         if(strcmp(operation_type, "erase") == 0) {
//             int pos;
//             scanf("%d", &pos);
//             erase(pos);
//         }

//         if(strcmp(operation_type, "swap") == 0) {
//             int pos;
//             scanf("%d", &pos);
//             swap(pos);
//         }

//         if(strcmp(operation_type, "index_into") == 0) {
//             int n;
//             scanf("%d", &n);
//             for(int i=0;i<n;i++) scanf("%d", &indices[i]);
//             struct Node* new_head = index_into(indices, n);
//             print_list(new_head);
//         }

//         if(strcmp(operation_type, "sort") == 0) {
//             sort();
//         }
//     }
// }

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    char* emp_name;
    int emp_salary;
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int id, char* name, int salary) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = id;
    ptr->emp_salary = salary;
    ptr->emp_name = strdup(name);
    // strdup() creates a copy of the string or char pointer and stores it in the new char pointer of the employee
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int id, salary;
    char name[100];
    scanf("%d", &id);
    if(id == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present

    scanf("%s %d", name, &salary);
    struct Employee* par = create_employee(id, name, salary);

    par->subordinate_1 = create_company();
    par->subordinate_2 = create_company();
    
    return par;
}

// The following function 
void print_company_helper(struct Employee* ceo) {
    // take input
    if(!ceo) {
        printf("%d ", -1);
        return;
    }
    printf("%d %s %d ", ceo->emp_id, ceo->emp_name, ceo->emp_salary);
    print_company_helper(ceo->subordinate_1);
    print_company_helper(ceo->subordinate_2);
    return;
}

void print_company(struct Employee* ceo) {
    print_company_helper(ceo);
    printf("\n");
    return;
} 

// --------------------------------------------------- YOU CAN EDIT BELOW THIS LINE -----------------------------------

struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company

int Boss_helper(int emp_id, struct Employee* boss){
    struct Employee* sub1 = boss->subordinate_1;
    struct Employee* sub2 = boss->subordinate_2;
    if(sub1 != NULL){
        if(sub1->emp_id == emp_id){
            return boss->emp_id;
        }
    }
    
    if(sub2 != NULL){
        if(sub2->emp_id == emp_id){
            return boss->emp_id;
        }
    }
    
    int boss1;
    int boss2;

    if(sub1 != NULL){
        boss1 = Boss_helper(emp_id,sub1);
    }else{
        boss1 = -1;
    }
    if(sub2 != NULL){
        boss2 = Boss_helper(emp_id,sub2);
    }else{
        boss2 = -1;
    }

    if(boss1 != -1){
        return boss1;
    }
    if(boss2 != -1){
        return boss2;
    }
    return -1;
}
int Boss(int emp_id) {
    if(emp_id == CEO->emp_id){
        return -1;
    }
    
    int boss_id = Boss_helper(emp_id,CEO);
    return boss_id;
}
// The following function returns the level of a employee with the given emp_id
int Level(int emp_id) {
    // Note that ceo has level 0
    int level = 0;
    int boss = emp_id;
    int ceo = CEO->emp_id;
    while(boss!=ceo){
        boss = Boss(boss);
        level++;
    }
    return level;
}
// The below function returns the employee id of the first common boss
int get_first_common_boss(int emp_id1,int emp_id2){
    int diff = Level(emp_id1) - Level(emp_id2);
    if(diff == 0){
        int boss1 = Boss(emp_id1);
        int boss2 = Boss(emp_id2);
        while(boss1!=boss2){
            boss1 = Boss(boss1);
            boss2 = Boss(boss2);
        }
        if(boss1==boss2){
        return boss1;
        }
    }else if(diff<0){                          //this means level(e1)<level(e2)
        int boss1 = (emp_id1);
        int boss2 = (emp_id2);
        for(int i=0;i<=(-diff)-1;i++){
            boss2 = Boss(boss2);
        }while(boss1!=boss2){
            boss1 = Boss(boss1);
            boss2 = Boss(boss2);
        }
        if(boss1==boss2){
            return boss1;
        }
    }else if(diff>0){                          //this means level(e1)>level(e2)
        int boss1 = (emp_id1);
        int boss2 = (emp_id2);
        for(int i=0;i<=(diff)-1;i++){
            boss1 = Boss(boss1);
        }while(boss1!=boss2){
            boss1 = Boss(boss1);
            boss2 = Boss(boss2);
        }
        if(boss1==boss2){
            return boss1;
        }
    }
    return 0;
}

struct Employee* ImmTeam_helper(int emp_id, struct Employee* boss){
    struct Employee* sub1 = boss->subordinate_1;
    struct Employee* sub2 = boss->subordinate_2;
    if(sub1 != NULL){
        if(sub1->emp_id == emp_id){
            return boss;
        }
    }
    
    if(sub2 != NULL){
        if(sub2->emp_id == emp_id){
            return boss;
        }
    }
    
    struct Employee* boss1;
    struct Employee* boss2;

    if(sub1 != NULL){
        boss1 = ImmTeam_helper(emp_id,sub1);
    }else{
        boss1 = NULL;
    }
    if(sub2 != NULL){
        boss2 = ImmTeam_helper(emp_id,sub2);
    }else{
        boss2 = NULL;
    }

    if(boss1 != NULL){
        return boss1;
    }
    if(boss2 != NULL){
        return boss2;
    }
    return NULL;
}

struct Employee* employeePtr_helper(int emp_id) {
    struct Employee* empl;
    if(CEO->emp_id == emp_id){
        empl = CEO;
    }else{
        struct Employee* boss = ImmTeam_helper(emp_id,CEO);
        if(boss->subordinate_1!=NULL){
            if((boss->subordinate_1)->emp_id == emp_id){
                empl = boss->subordinate_1;
            }
        }
        if(boss->subordinate_2!= NULL){
            if((boss->subordinate_2)->emp_id == emp_id){
                empl = boss->subordinate_2;
            }
        }
    }
    return empl;
}
//Print the employees with the same last name sperated by a space in the order of their level
void lastNameHelper(struct Employee* curr,struct Employee* ptr){
    if(curr==NULL){
        return;
    }
    if(strcmp(curr->emp_name,ptr->emp_name)==0){
        append(curr->emp_id);
        // printf("%d", curr->emp_id);
    }
    // printf("%s",curr->emp_name);
    struct Employee* sub1 = curr->subordinate_1;
    struct Employee* sub2 = curr->subordinate_2;
    lastNameHelper(sub1,ptr);
    lastNameHelper(sub2,ptr);
    return;
}

void same_last_names(int emp_id){
    struct Employee* ptr = employeePtr_helper(emp_id);
    lastNameHelper(CEO,ptr);
    int n = len();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            int x = Level(getitem(j));
            int y = Level(getitem(j+1));
            if(x > y) swap(j);
        }
    }
    
    print_list(PythonListHead);
    clear();
    // printf("%d",empl->emp_id);
    return;
}

// Print the bosses of the given employee in the order from CEO to immediate boss
void get_all_bosses(int emp_id){
    int boss;
    if(emp_id!=CEO->emp_id){
        while(CEO->emp_id!=emp_id){
            boss = Boss(emp_id);
            append(boss);
            emp_id = boss;
        }
    }else{
        append(Boss(emp_id));
    }
    reverse();
    print_list(PythonListHead);
    clear();
    return;
}

// Return the average salary of the team with the given employee as head
void avg_salary_helper(struct Employee* ceo,double* Netsalary, double* counter) {
    // take input
    if(!ceo) {
        return;
    }
    (*Netsalary) = (*Netsalary) + ceo->emp_salary;
    (*counter) = (*counter) + 1;
    avg_salary_helper(ceo->subordinate_1,Netsalary,counter);
    avg_salary_helper(ceo->subordinate_2,Netsalary,counter);
    return;
}
double get_average_salary(int emp_id){
    double Netsalary = 0;
    double counter = 0;
    struct Employee* ptr = employeePtr_helper(emp_id);
    avg_salary_helper(ptr,(&Netsalary),(&counter));
    double avg_salary = (Netsalary)/(counter);
    return avg_salary;
}
// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------

/* The following driver code creates a organisation for you and based on the input file
it will call all the functions that are necessary, your job is to edit the functions
above the line. Their descriptions are in the pdf and in the comments in the code. */

int main(int argc, char const *argv[])
{
    CEO = create_company();
    print_company(CEO);

    int T; 
    scanf("%d", &T);

    char operation_type[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "get_first_common_boss") == 0) {
            int x,y;
            scanf("%d %d", &x, &y);
            int ans = get_first_common_boss(x,y);
            printf("%d\n", ans);
        } 
        else if(strcmp(operation_type, "same_last_names") == 0) {
            int x;
            scanf("%d", &x);
            same_last_names(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_all_bosses") == 0) {
            int x;
            scanf("%d", &x);
            get_all_bosses(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_average_salary") == 0) {
            int x;
            scanf("%d", &x);
            double ans = get_average_salary(x);
            printf("%.2f\n", ans);
        } 

    }

    return 0;
}
