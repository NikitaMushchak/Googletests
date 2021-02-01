#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <bitset>

#include <algorithm>

typedef  std::vector<int> vint;


bool isPrime(const int number) {
    if (number <= 1) {
        return false;
    }
    double num_double = (double)number;
    double max_number = sqrt(num_double);
    int max_int = int(max_number);
    for (int i = 2; i <= max_int; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

vint primesToArray(const int N) {
    vint array;
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            array.push_back(i);
        }
    }
    return array;
}
vint primesToArrayEratosfen(const int N) {
    std::vector<bool> sieve(sqrt(N));
    vint primes;

    for (int i = 2; i <= N; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j+=i) {
                sieve[j] = 1;
            }
        
        }
    }
    return primes;
}


// func to count the words in text
int countWords(const std::string& str) {
    return std::count(str.begin(), str.end(), ' ') + 1;
}

// func to count the words in text
int countWordsModified(std::string& str) {
   
    int count = 0;
    
    for (int i = 0; i < str.size()-1; ++i) {
        if (isalpha(str[i]) && !isalpha(str[i + 1])) {
            ++count;
            str.erase(str.begin(), str.begin() +i+1);
            i = 0;
        }
    }
    if (isalpha(str[str.size() - 1])) {
        count++;    
    }
    return count;
}

int maxLetters(std::string str) {

   
    int max = 0;
    for (int i = 0; i < str.size() - 1; ++i) {
        if (str[0] == ' ') {
            str.erase(str.begin(), str.begin() + 1);
            i--;
        }
        if (isalpha(str[i]) && !isalpha(str[i + 1])) {
           
            if (max < i+1) {
                max = i+1;
            }
            str.erase(str.begin(), str.begin() + i + 1);
            i = 0;
        }
    }
    if (isalpha(str[str.size() - 1])) {
        if (max < str.size()) {
            max = str.size();
        }
       
    }
    return max;
}

//2. function that counts the number of words in the text for each word length
std::vector<int> countWordsInString(std::string& str){
    if (str.size() == 0) {
        return std::vector<int>{0};
    }
    std::vector<int> words; //vector which stored number of words
    //                           index = 0 - words consisits 1 letter
    //                           index = 1 - words consisits 2 letters
    //                           index = 2 - words consisits 3 letters and ...
    
    words.resize(maxLetters(str));
    std::string buf;
    for (int i = 0; i < str.size(); ++i) {
        if (str[0] == ' ') {
            str.erase(str.begin(), str.begin() + 1);
            i--;
        }
        if (isalpha(str[i]) && !isalpha(str[i + 1])) {
            words[i] = words[i]+1;
            str.erase(str.begin(), str.begin() + i + 1);
            i = 0;
        }
    }
    for (int i = 0; i < words.size(); ++i) {
        if (words[i] > 0) {
            std::cout << words[i] << " words with " << i + 1 << "-letter length" << std::endl;
        }
    }
    return words;
}
//3 There is a list:
struct List {
    struct List* next;
    int payload;
};
//a function that removes every fifth (5) element from this list
void deleteEveryFifthFromList(List* list, int sizeoflist) {
    if (sizeoflist < 5) {
        return;
    }
    //number of elements to delete from List
    int numberofdeleteelements = sizeoflist / 5;
    //size of new List
    const int numberofnewelements = sizeoflist - numberofdeleteelements;
    // New List
    List* newList = new List[numberofnewelements];
    // fill newList with elements
    for (int iter = 0, iterofoldlist = 0; iter < numberofnewelements; ++iter) {
        
        if ((iterofoldlist + 1) % 5 == 0) {
            newList[iter].payload = list[iterofoldlist + 1].payload;
            //bufferlist[iter].next = list[iterinilist].next;
            newList[iter - 1].next = list[iterofoldlist].next;
            newList[iter].next = list[iterofoldlist + 1].next;
            iterofoldlist += 2;

        }
        else {
            newList[iter].payload = list[iterofoldlist].payload;
            newList[iter].next = list[iterofoldlist].next;
            iterofoldlist++;
        }
    }
    delete [] list;
    for (int iter = 0; iter < numberofnewelements; ++iter) {
        list[iter].next = newList[iter].next;
        list[iter].payload = newList[iter].payload;
    }
    delete[] newList;
    
}

//4 Write a function that takes a 32-bit unsigned integer number and returns the maximum
//and minimum 32 - bit unsigned integer numbers which can be obtained using the same
//number of bits set to 1 as in the taken number.
//void func(unsigned long a){
//
//}


struct TreeNode {
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};
//structure to define left and rigth child of root
typedef enum typeTreeNode {LEFT_CHILD, RIGTH_CHILD} NODE_TYPE;
// create root object
TreeNode* root = NULL;
//add nodes to TreeNode // add left child by default
TreeNode* addTreeNode(TreeNode *tree, NODE_TYPE type = LEFT_CHILD) {
    //create new treeNode
    TreeNode* ptr = new TreeNode;
    
    //initailization of child
    ptr->leftChild = NULL;
    ptr->rightChild = NULL;
    //if tree is root
    if (tree == NULL) {
        root = ptr;
    }
    else { // if object allready exsisits
        switch (type) {
        case RIGTH_CHILD:
            tree->rightChild = ptr;
            break;
        case LEFT_CHILD:
            tree->leftChild = ptr;
        }
    }
    return ptr;
}

//func to show obj
void showObj(TreeNode* obj) {
    if (obj == NULL) {
        return;
    }
    //show pointer to obj
    std::cout << obj << std::endl;

    showObj(obj->leftChild);
    showObj(obj->rightChild);

}
//func to show all tree
void showTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    std::cout << root << std::endl;
    showObj(root->leftChild);
    showObj(root->rightChild);
}

// max depth of Tree
int maxTreeDepth(TreeNode*& obj) {
    if (obj == NULL) {
        return 0;
    }
    else {
        int leftdepth = maxTreeDepth(obj->leftChild);
        int rightdepth = maxTreeDepth(obj->rightChild);

        if (leftdepth <= rightdepth) {
            return rightdepth + 1;
        }
        else {
            return leftdepth + 1;
        }
    }
}

//func that returns max depth of the tree and push_back max leaf's pointer
int maxTreeDepthPointer(TreeNode*& obj, std::vector<TreeNode*>& leafpointer) {
    if (obj == NULL) {
        return 0;
    }
    else {
        int leftdepth = maxTreeDepthPointer(obj->leftChild, leafpointer);
        int rightdepth = maxTreeDepthPointer(obj->rightChild, leafpointer);

        if (leftdepth <= rightdepth) {
            leafpointer.push_back(obj->rightChild);
            return rightdepth + 1;
        }
        else {
            leafpointer.push_back(obj->leftChild);
            return leftdepth + 1;
        }
    }
}
void printPath(std::vector<TreeNode*>& path) {
    for (int iter = 0; iter < path.size(); ++iter) {
        std::cout << "pointer # " << iter << " = " << path[iter] << std::endl;
    }
}
//prototypes of the functions
void printPaths(TreeNode* node);
void printPathsRecur(TreeNode* node, std::vector<TreeNode*> path, int pathlen);

void printPaths(TreeNode* node) {

    std::vector<TreeNode*> path;
    printPathsRecur(node, path, 0);
}

void printPathsRecur(TreeNode* node, std::vector<TreeNode*> path, int pathlen) {
    if (node == NULL) {
        return;
    }
    path.push_back(node);
    pathlen++;

    if (node->leftChild == NULL && node->rightChild == NULL) {
        printPath(path);
    }
    else {
        printPathsRecur(node->leftChild, path, pathlen);
        printPathsRecur(node->rightChild, path, pathlen);
    }

}
std::vector<std::vector<TreeNode*> > allPaths(TreeNode* node, int maxdepth);
void allPathsRecursive(TreeNode* node, std::vector<TreeNode*> path, std::vector<std::vector<TreeNode*> >& paths, int pathlen, int maxdepth);

std::vector<std::vector<TreeNode*> > allPaths(TreeNode* node, int maxdepth) {
    std::vector<std::vector<TreeNode*> > paths;
    std::vector<TreeNode*> path;
    allPathsRecursive(node, path, paths, 0, maxdepth);

    return paths;
}

void allPathsRecursive(TreeNode* node, std::vector<TreeNode*> path, std::vector<std::vector<TreeNode*> >& paths, int pathlen, int maxdepth) {
    if (node == NULL) {
        return;
    }
    

    path.push_back(node);
    pathlen++;

    if (node->leftChild == NULL && node->rightChild == NULL) {
        //printPath(path);
        if (path.size() == maxdepth) {
            paths.push_back(path);
        }
    }
    else {
        allPathsRecursive(node->leftChild, path,  paths, pathlen, maxdepth);
        allPathsRecursive(node->rightChild, path, paths, pathlen, maxdepth);
    }

}
void showPaths(std::vector<std::vector<TreeNode*> >& paths) {
    for (int iterofpaths = 0; iterofpaths < paths.size(); ++iterofpaths) {
        std::cout << "num of path : " << iterofpaths << std::endl;
        for (int iterofleafs = 0; iterofleafs < paths[iterofpaths].size(); ++iterofleafs) {

            std::cout << "->" << paths[iterofpaths][iterofleafs];
        }
        std::cout << " \n";
    }

}

//paths to node obj from root
bool pathToObj(TreeNode* root, TreeNode* obj, std::vector<TreeNode*>& path) {
    //vector of pointers
    
    if (obj == NULL) {
        return false;
    }
   
    //push root's pointer
    path.push_back(root);
    
    //if it is requred obj we return true
    if (root == obj) {
        return true;
    }

    if (pathToObj(root->leftChild, obj, path) || pathToObj(root->rightChild, obj, path)) {
        return true;
    }

    // required node does not lie either in the  
    // left or right subtree of the current node 
    // Thus, remove current node's pointer from  
    // 'path'and then return false     
    path.pop_back();
    return false;
}

// a function that takes a 32 - bit unsigned integer number and returns the maximum
//and minimum 32 - bit unsigned integer numbers which can be obtained using the same
//number of bits set to 1 as in the taken number.

std::pair<unsigned long, unsigned long> getMinAndMax(unsigned long& number) {
    std::pair <unsigned long, unsigned long> output;

    std::bitset<32> bitsetofnumber(number);
    

    std::string stringnumber = bitsetofnumber.to_string();
    

    //how many 1 is in number
    int numofbytes = 0;
    for (int iter = 0; iter < stringnumber.size(); ++iter) {
        if (stringnumber[iter] == '1')
            numofbytes++;
    }

    
    std::string minnumberstring(32, '0');
    std::string maxnumberstring(32, '0');
    for (int iter = 0; iter < 32; ++iter) {
        if (iter < numofbytes) {
            maxnumberstring[iter] = '1';
        }
        else {
            maxnumberstring[iter] = '0';
        }

        if (32 - iter <= numofbytes) {
            minnumberstring[iter] = '1';
        }
        else {
            minnumberstring[iter] = '0';
        }
    }

    
    std::bitset<32> maxnumberbitset(maxnumberstring);
    std::bitset<32> minnumberbitset(minnumberstring);
   
    output.second = maxnumberbitset.to_ulong();
    output.first = minnumberbitset.to_ulong();
    return output;
}
