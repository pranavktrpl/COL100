#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int x) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = x;
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int x;
    scanf("%d", &x);

    if(x == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present
    struct Employee* par = create_employee(x);

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
    printf("%d ", ceo->emp_id);
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

/* The following function takes an emp_id this will belong to a employee in the organisation and your task is to return the emp_id of its boss
Note: If the boss does not exit return -1 */

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

/*  In this function you have to print all the employees at a given level, Note that ceo is at level 0
In any of the functions which involve printing you need not print -1 for NULL pointers */

void emplevel_helper(int level, struct Employee* emp){
    if(emp==NULL){
        return;
    }else{
        if(Level(emp->emp_id)==level){
            printf("%d ",emp->emp_id);
            return;
        }else{
            struct Employee* sub1 = emp->subordinate_1;
            struct Employee* sub2 = emp->subordinate_2;

            emplevel_helper(level,sub1);
            emplevel_helper(level,sub2);
            return;
        }
    }
}

void EmployeesAtSameLevel(int level) {
    // The level may be any integer
    emplevel_helper(level,CEO);
    return;
}

// You have to print the employees as you search the organization look for the examples in the pdf and the input.txt and output.txt for details
// Note: You do not have to print -1 for NULL pointers

void get_employees_helper(struct Employee* emp){
    if(emp == NULL){
        return;
    }else{
        int empid = emp->emp_id;
        printf("%d ", empid);
        get_employees_helper(emp->subordinate_1);
        get_employees_helper(emp->subordinate_2);
    }
}

void get_employees() {                              //we can just call print_organization(Organization) but it prints -1;
    get_employees_helper(CEO);
    return;
}

/* In the following function you have to print the immediate team of a employee - it includes their boss and their subordinates
Note: You do not have to print -1 for NULL pointers */

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

void ImmediateTeam(int emp_id) {
    int boss = Boss(emp_id);

    struct Employee* empl;
    int sub1 = -1;
    int sub2 = -1;

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

    if(empl->subordinate_1 != NULL){
        sub1 = (empl->subordinate_1)->emp_id;
    }
    if(empl->subordinate_2 != NULL){
        sub2 = (empl->subordinate_2)->emp_id;
    }
    
    if(boss != -1){
        printf("%d ", boss);
    }
    if(sub1 != -1){
        printf("%d ", sub1);
    }
    if(sub2 != -1){
        printf("%d ",sub2);
    }

    return;
}

// The following function gives the distance between employees with emp_id1 and emp_id2
int Distance(int emp_id1, int emp_id2) {
    // If emp_id1 and emp_id2 are equal the distance is 0, both emp_id's will exist in the organisation
    if(emp_id1==emp_id2){
        return 0;
    }else{
        int Distance = 0;
        int level1 = Level(emp_id1);
        int level2 = Level(emp_id2);
        int diff = level1-level2;
        int boss1 = emp_id1;
        int boss2 = emp_id2;
        if(diff == 0){
            while(boss1!=boss2){
                boss1 = Boss(boss1);
                boss2 = Boss(boss2);
                Distance = Distance+2;
            }
            return Distance;
        }
        if(diff>0){
            for(int i=1;i<=diff;i++){
               boss1 = Boss(boss1);
               Distance++;
            }
            while(boss1!=boss2){
                boss1 = Boss(boss1);
                boss2 = Boss(boss2);
                Distance = Distance+2;
            }
            return Distance;
        }
        if(diff<0){
            for(int i=1;i<=(-diff);i++){
               boss2 = Boss(boss2);
               Distance++;
            }
            while(boss1!=boss2){
                boss1 = Boss(boss1);
                boss2 = Boss(boss2);
                Distance = Distance+2;
            }
            return Distance;
        }

    }
}

/* The following function returns the diameter of a Organisation - 
a diameter is the maximum distance between any two emp_ids in the organisation. You can use the distance function implemented above */

int longestdist(struct Employee* emp){
    if(emp == NULL){
        return 0;
    }
    int leftdist = longestdist(emp->subordinate_1);
    int rightdist = longestdist(emp->subordinate_2);

    int longdist;
    if(leftdist>rightdist){
        longdist = leftdist;
    }else{
        longdist = rightdist;
    }

    return (longdist+1);
}

int Diameter_Helper(struct Employee* emp){

    if(emp == NULL){
        return 0;
    }
 
    int leftdist = longestdist(emp->subordinate_1);
    int rightdist = longestdist(emp->subordinate_2);
 
    int leftdia = Diameter_Helper(emp->subordinate_1);
    int rightdia = Diameter_Helper(emp->subordinate_2);
    
    int lowerdia;
    if(leftdia>rightdia){
        lowerdia = leftdia;
    }else{
        lowerdia = rightdia;
    }
    
    int Diameter;

    if(leftdist+rightdist>lowerdia){
        Diameter = leftdist + rightdist;
    }else{
        Diameter = lowerdia;
    }
    
    return Diameter;
}

int Diameter() {                         // use distance from ceo to the point at max and find if greater then prev dist, update dist.
    int dia = Diameter_Helper(CEO);
    return dia;
}

/* The following function takes an emp_id of a employee and returns the number of employees directly connected to it.
NULL pointers are not included */

int TeamSize(int emp_id) {
    int boss = Boss(emp_id);

    struct Employee* empl;
    int sub1 = -1;
    int sub2 = -1;

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

    if(empl->subordinate_1 != NULL){
        sub1 = (empl->subordinate_1)->emp_id;
    }
    if(empl->subordinate_2 != NULL){
        sub2 = (empl->subordinate_2)->emp_id;
    }
    
    int counter = 0;

    if(boss != -1){
        counter++;
    }
    if(sub1 != -1){
        counter++;
    }
    if(sub2 != -1){
        counter++;
    }

    return counter;
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

    char operation_type[20];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "level") == 0) {
            int x;
            scanf("%d", &x);
            int d = Level(x);
            printf("%d\n", d);
        } 

        if(strcmp(operation_type, "distance") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            int d = Distance(x, y);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "employees_at_same_level") == 0) {
            int x;
            scanf("%d", &x);
            EmployeesAtSameLevel(x);
            printf("\n");
        }

        if(strcmp(operation_type, "get_employees") == 0) {
            get_employees();
            printf("\n");
        }

        if(strcmp(operation_type, "boss") == 0) {
            int x;
            scanf("%d", &x);
            int d = Boss(x);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "diameter") == 0) {
            int d = Diameter();
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "immediate_team") == 0) {
            int x;
            scanf("%d", &x);
            ImmediateTeam(x);
            printf("\n");
        }

        if(strcmp(operation_type, "team_size") == 0) {
            int x;
            scanf("%d", &x);
            int d = TeamSize(x);
            printf("%d\n", d);
        }
    }

    return 0;
}
