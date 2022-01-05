#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

///Declare some basic informations structure of a student.

struct student{
    char Sem[10];
	char Name[20],Address[20], Telephone[15],Class[10],ID[10];
	struct student *left,*right,*parent;
};

struct student *node;

///Function declaration for binary tree data structure.
void AddStudent(char *Name,char *Id,char *Add,char *Tel,char *Class,char *Semester);
///The function below need to be fixed because segmentation fault occurs.
/*void PrintRecord(struct student *node);*/
///
void PrintStudent(struct student *node,char *name);
void RecurInsertStudent(struct student *node,struct student *newStudent );
int delete(struct student *remove, char *name);
///These functions below need also to be fixed because segmentation faults occur.
int WriteList(const struct student *node);
int ReadList(void);
int SaveList(const struct student *node,FILE *list);

struct student *root = NULL;
struct student *findMin(struct student *node);
struct student *findMax(struct student *node);
struct student *findHeight(struct student *node);
struct student *Remove(struct student *remove);
struct student *search(struct student *node,char *name);
//struct student *searchID(struct student *node,char* id);

int count = 0;

///Function definition for binary tree data structure.
/*Function to add new student and save to the database*/
void AddStudent(char *Name,char *Id,char *Add,char *Tel,char *Class,char *Semester){
    // Create the new student:
    count++; // counter incremented
    // Allocates memory for new Nodes
    struct student *newStudent = (struct student *) malloc(sizeof(struct student));

    strcpy(newStudent->Name,Name);
    strcpy(newStudent->ID,Id);
    strcpy(newStudent->Address,Add);
    strcpy(newStudent->Telephone,Tel);
    strcpy(newStudent->Class,Class);
    strcpy(newStudent->Sem,Semester);

    newStudent->left = NULL;
    newStudent->right = NULL;
    newStudent->parent = NULL;
	

    // Checks if database is empty
    if (root == NULL ){
        root = newStudent;
        root->left   = NULL;
        root->right  = NULL;
        root->parent = NULL;
        return;
    }
    // Adding student recursively
    else{
        RecurInsertStudent(root, newStudent);
        return;
    }
}
/* Insert student in the binary tree
 * adds a new binary students - sorted alphabetically
 * doesn't allow addition of students with the same name
 * create and choose the condition to insert the node.
 */

void RecurInsertStudent(struct student *node, struct student *newStudent){
    /* Alphabetical Ordering: if the result of string compare == 0
       that means that the Student already exists.*/
    if (strcmp(newStudent->Name, node->Name) == 0) {printf("\nName already exist.");}
	
    /* Alphabetical Ordering: if the result of string compare > 0
       that means the Student goes to the right.*/
    if (strcmp(newStudent->Name, node->Name) > 0) {
        if (node->right == NULL){
            node->right = newStudent; newStudent->parent = node;
            return;}
        //if there is no more branch to move to, add student profile here
        else {RecurInsertStudent(node->right, newStudent);}
    }

    /* Alphabetical Ordering: if the result of string compare < 0
       that means the Student goes to the left */
    if(strcmp(newStudent->Name, node->Name) < 0) {
        if(node->left == NULL){
            node->left = newStudent;
            newStudent->parent = node;
            return;}
        //if there is no more branch to move to, add student profile here
        else {RecurInsertStudent(node->left, newStudent);}
    }
}


// Recursive Function : Prints all Students Info in Alphabetical Order from left to right
/*void PrintRecord(struct student*node){
    // Check the database is whether empty or not
    if(root==NULL){return;}
    // Print from left to right
    if(node->left){PrintRecord(node->left);}
    printf("\n\tName: --- %s",node->Name);
    printf("\n\tClass: --- %s",node->Class);
    printf("\n\tID number: --- %s",node->ID);
    printf("\n\tAddress: --- %s",node->Address);
    printf("\n\tTelephone: --- %s",node->Telephone);
    printf("\n\tSemester: --- %d",node->Sem);
    printf("\n");
    if(node->right){PrintRecord(node->right);}
}*/

// this function displays a singular student record
void PrintStudent(struct student *node, char *name){
    node = search(root,name);
    if(node != NULL){
        printf("\n\t\t[1] - Name: --- %s\n",node->Name);
        printf("\n\t\t[2] - Class: --- %s\n",node->Class);
        printf("\n\t\t[3] - ID number: --- %s\n",node->ID);
        printf("\n\t\t[4] - Address: --- %s\n",node->Address);
        printf("\n\t\t[5] - Telephone: --- %s\n",node->Telephone);
        printf("\n\t\t[6] - Semester: --- %s\n",node->Sem);
    }else{printf("\n\t ---------- Student Not Found !!---------- ");}
}

// Recursive Function : insert each struct in the list in alphabetical order
int sc = 0; 
int SaveList(const struct student *node, FILE *f){
    if (node == NULL) return 0;
 	else{
    		if (sc) {
    			fputs("\n",f);
    			fputc('\n',f);
			}
			/*1*/	fputs(node->Sem,f); fputs("\n",f);
    		/*2*/	fputs(node->Name,f); fputs("\n",f);
    		/*3*/	fputs(node->Address,f); fputs("\n",f);
   		 	/*4*/	fputs(node->Telephone,f); fputs("\n",f);
    		/*5*/	fputs(node->Class,f); fputs("\n",f);
    		/*6*/	fputs(node->ID,f); 
    		sc++;   		
	}
	
	
	if (node->left != NULL) {
        SaveList(node->left,f);
    }
    
    if (node->right != NULL) {
        SaveList(node->right,f);
    }
    return 2;
}

//save the list in a file
int WriteList(const struct student *node){
    char* filename = "StudentList_w.sav";
	FILE *f = fopen(filename,"w");
	
	if (f == NULL){
		printf("Could not open file %s",filename);
        return 1;	
	}
	sc = 0; 
    if (2 == SaveList(root, f) ) printf("Save Student List Successfully!\n");
    else {
    	return 1;
    	fclose(f);
	} 
    fclose(f);
    return 0; 
}

// Opens the file previously created and reads the data from it
int ReadList(void){
	char* filename = "StudentList_r.sav";
	FILE* f = fopen(filename,"r"),*f1;
	f1 = f;
	
	if (f == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    
    char* buffer[6],a='A';
    int i;
    for (i=0;i<6;i++){
    	buffer[i] = (char*) malloc((size_t) 20*sizeof(char)); 
	}
	
	while (1){
		int j;
		for (j=0;j<6;j++){
			fgets(buffer[j],20,f);
    		fflush(stdin);
    		buffer[j][strlen(buffer[j])-1] = '\0'; //clear line-breaks
    	}
	
		char* newname = convertStdName(buffer[1]);
		//0: Semester
		//1: Name
		//2: Address
		//3: Telephone
		//4: Class
		//5: ID
		AddStudent(newname,buffer[5],buffer[2],buffer[3],buffer[4],buffer[0]);	
		free(newname);
		a = fgetc(f);
		if (a == EOF) break; 
	}
	
	for (i=0;i<6;i++) free(buffer[i]);
    fclose(f);
    return 0;
}

//find the most left leaf
struct student *findMin(struct student *node)
{
    if (node->left == NULL){return node;}
    else{findMin(node->left);}
    return NULL;
}


struct student *findMax(struct student *node){
    while (node->right != NULL ){return findMax(node->right);}
    return node;
}

// Recursive Function : searches the tree by diving it in half
struct student *search(struct student *node, char *name){
    if(node == NULL){printf("Not found.\n");return NULL;}

    //if strcmp result < 0 we search for the tudent in left child
    if(strcmp(name, node->Name) < 0){
        if(node->left){return search(node->left,name);}
        else{return NULL;}
    }

    //if strcmp result > 0 we search for the student in right
    if(strcmp(name, node->Name) > 0){
        if(node->right){return search(node->right,name);}
        else{return NULL;}
    }

    //if strcmp result == 0 return node
    if(strcmp(name, node->Name) == 0){return node;}
    return node;
}



// finds height of tree recursively
struct student *findHeight(struct student *node){
    // if the input is NULL return 0
    if(node == NULL){return 0;}
    struct student *left;
    struct student *right;

    // check left node's height and rights
    left  = findHeight(node->left);
    right = findHeight(node->right);

    /*if left is bigger return left's height plus one for the current node
     else return right's height plus one*/
    if(left > right){return left + 1;}
    else {return right + 1;};
}

// right rotates a node
void rightRotateBinary(struct student *node){
    struct student *temp;
    struct student *original;
    struct student *left;
    //checks if node that was passed was null or had no left children
    if(node == NULL || node->left == NULL){return;}
    original = node;
    left = original->left;
    temp = (struct student *) malloc(sizeof(struct student));
    // copies info from org node to temp
    strcpy(temp->Name, original->Name);
    strcpy(temp->ID, original->ID);
    // copies info from left node to org node
    strcpy(original->Name,left->Name);
    strcpy(original->ID, left->ID);
    // moves temp between the org and right and saves value of left's left
    temp->left = left->right;
    temp->right = original->right;
    original->left = left->left;
    original->right = temp;
    // frees old left value
    free(left);
}

// left rotates a node
void leftRotateBinary(struct student *node){
    struct student *temp;
    struct student *original;
    struct student *right;
    // checks if node that was passed was null or had no right children
    if(node == NULL || node->right == NULL){return;}
    original = node;
    right = original->right;
    temp = (struct student *) malloc((size_t)sizeof(struct student));
    // copies info from original node to temp
    strcpy(temp->Name, original->Name);
    strcpy(temp->ID, original->ID);
    // copies info from right node to original node
    strcpy(original->Name, right->Name);
    strcpy(original->ID, right->ID);
    // moves temp between the original and left and saves value of right's right
    temp->right = right->left;
    temp->left = original->left;
    original->right = right->right;
    original->left = temp;
    // frees old right value
    free(right);
}

// Balances a binary tree through Day-Stout-Warren algorithm
void balanceBinary(struct student *root){
    struct student *node;
    int expected, oddNodes;
    int numNodes = 0;
    node = root;
    // Unfolds tree by right rotating until there are no more left children
    while (node != NULL){
        while(node->left != NULL){
            rightRotateBinary(node);
        }
        node = node->right;
        numNodes++;
    }
    // Calculates floor nodes through 2n-1 as sum of 2^i from 0 to n is equal to 2^(n+1) - 1
    expected = numNodes - (pow(2,(floor(log2(numNodes+1)))) - 1);
    node = root;
    //folds expected floor values
    for(int i = 0; i < expected; i++){
        leftRotateBinary(node);
        node = node->right;
    }
    // rotates odd nodes along tree
    node = root;
    numNodes = numNodes - expected;
    oddNodes = (numNodes+1)/2;
    while(oddNodes > 1){
        //left rotates root
        leftRotateBinary(root);
        //rotates odd nodes along the rest of the tree
        for(int i = 0; i < (oddNodes-1); i++){
            leftRotateBinary(node->right);
            node = node->right;
        }
        //increments odd nodes
        oddNodes = (oddNodes+1)/2;
    }
}

//Given a binary search tree and a name and an ID,
//this function checks the existence of name and ID
//and returns the new root to be deleted
int delete(struct student *remove, char *name){
    // search the database for name as well as ID and assign it remove
    remove = search(root,name);
    if (remove == NULL) return 1;
    struct student *var1 = NULL;
    struct student *var2 = NULL;
    struct student *var3 = NULL;

    if(remove->parent){
        // if remove node has a parent
        struct student *Parent = remove->parent;
        if(Parent -> parent){
            var1 = Parent->parent;
                if(var1 -> left == Parent){
                    var2 = var1 -> left;}
                else {
                    var3 = var1 -> right;}
        }
        if(Parent->left == remove){
            Parent->left = NULL;
            remove->parent = NULL;
            if((var2 != NULL) && (var3 != NULL)){
                var1 -> left = Parent;
                var1 -> right = Parent;
                return 0;
            }
        }
        else{
            Parent->right=NULL;
            remove->parent=NULL;
            struct student *del = Remove(remove);
            if(del != NULL){
                del->parent=Parent;
                Parent->right = del;}
                    if(del != NULL){}
            return 0;
        }
    }
    else{
        struct student *del = Remove(remove);
        root = del;
        return 0;
    }
}

//delete a student and balance its subtrees
struct student *Remove(struct student *remove){
    count--;
    if(remove->left){
        struct student *new = findMin(remove->left);
        // Get the findMin: (smallest in the left subtree)
        if(new->left){
            if(new->parent == remove){
                if (remove->right) remove->right->parent = new;
                remove->left = NULL;
                new->right = remove->right;  //Copy the remove content to this new node
                remove->right = NULL;
                new->parent = NULL;
                free(remove);
                balanceBinary(new); // balance binary tree after removal
                return new;
            }
            else{
                struct student *tmp = new->left;
                tmp->parent = new->parent;
                new->parent->right = tmp;
                remove->right = NULL;
                remove->left = NULL;
                if (new->right) new->right->parent = new;
                if (new->left) new->left->parent = new;
                new->parent = NULL;
                free(remove);
                return new;
            }
        }
        else{
            struct student *tmp = new->parent;
            if(tmp == remove){
                remove->left = NULL;
                new->right = remove->right;
                remove->right = NULL;
                new->parent = NULL;
                free(remove);
                balanceBinary(new); // balance binary tree after removal
                return new;
            }
            else{
                tmp->right  = NULL;
                new->parent = NULL;
                if(remove->right){ remove->right->parent = new;}
                remove->left->parent = new;
                new->left  = remove->left;
                new->right = remove->right;
                free(remove); // derefrence 'remove'
                return new;
            }
        }
    }
    if(remove->right){
        struct student *new = remove->right;
        remove->right=NULL;
        new->parent=NULL;
        free(remove);
        balanceBinary(new); // balances binary tree after removal
        return new;
    }
    if(remove->left == NULL && remove->right == NULL){free(remove);return NULL;}
    return remove;
}

#endif // STUDENT_H_INCLUDED
