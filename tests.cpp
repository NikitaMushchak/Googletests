#include "whattotest.cpp"
#include <bitset>
#include <gtest/gtest.h>


TEST(isPrimeTest, Zero) {
    ASSERT_TRUE(!isPrime(0));
    ASSERT_TRUE(!isPrime(-0));
   
}

TEST(isPrimeTest, PositiveNos) {
    ASSERT_TRUE(!isPrime(1));
    ASSERT_TRUE(isPrime(2));
    ASSERT_TRUE(isPrime(3));
    ASSERT_TRUE(!isPrime(4));
    ASSERT_TRUE(isPrime(5));
    ASSERT_TRUE(!isPrime(6));
    ASSERT_TRUE(isPrime(7));
    ASSERT_TRUE(!isPrime(8));
    ASSERT_TRUE(!isPrime(9));
    ASSERT_TRUE(isPrime(109));
    ASSERT_TRUE(!isPrime(111));
}

TEST(isPrimeTest, NeagiveNumbers) {
    ASSERT_TRUE(!isPrime(-1));
    ASSERT_TRUE(!isPrime(-2));
    ASSERT_TRUE(!isPrime(-3));
    ASSERT_TRUE(!isPrime(-4));
    ASSERT_TRUE(!isPrime(-5));
    ASSERT_TRUE(!isPrime(-6));
    ASSERT_TRUE(!isPrime(-7));
    ASSERT_TRUE(!isPrime(-8));
    ASSERT_TRUE(!isPrime(-9));
    ASSERT_TRUE(!isPrime(-109));
    ASSERT_TRUE(!isPrime(-111));
}


TEST(primesToArrayEratosfenTest, veccompdir) {
    const std::vector<int> a{ 2,3,5,7 };
    std::vector<int> b = primesToArrayEratosfen(7);
    ASSERT_EQ(a, b);
}


TEST(countWordsTest, stringcompdir) {
    const std::string a = "bbla bla c bla";
    ASSERT_EQ(4, countWords(a));
    const std::string b = "v e Vera.";
    ASSERT_EQ(3, countWords(b));
}

TEST(countWordsModifiedTest, stringcompdir2) {
    std::string a = "bbla bl ac bla ";
    ASSERT_EQ(4, countWordsModified(a));
    std::string b = "v e Vera.";
    ASSERT_EQ(3, countWordsModified(b));
}

TEST(mxLettersTest, maxletterst) {
    std::string a = "bbla bl ac bla ";
    ASSERT_EQ(4, maxLetters(a));
    std::string b = "v e Verab s";
    ASSERT_EQ(5, maxLetters(b));
    std::string c = "v e Verab";
    ASSERT_EQ(5, maxLetters(c));
}

TEST(countWordsInStringTest, countwordst) {
    std::string a = "aab a a a a ve";
    std::vector<int> av{ 4, 1, 1 };
    ASSERT_EQ(av, countWordsInString(a));
    std::string b = "v e Verab s.";
    std::vector<int> bv{ 3, 0,0,0, 1 };
    ASSERT_EQ(bv, countWordsInString(b));
    std::string c = "";
    std::vector<int> cv{0};
    ASSERT_EQ(cv, countWordsInString(c));

    std::string d = "a";
    std::vector<int> dv{1};
    ASSERT_EQ(dv, countWordsInString(d));

    std::string e = "@";
    std::vector<int> ev{ };
    ASSERT_EQ(ev, countWordsInString(e));
}

TEST(deleteEveryFifthFromListTest, nullptrList) {
    
    List* list  = nullptr;
    deleteEveryFifthFromList(list, 0);

    ASSERT_EQ(nullptr, list);
}

TEST(deleteEveryFifthFromListTest, testList) {

    const int lengthoflist = 11;
    List* list = new List[lengthoflist];
    List* testlist = new List[lengthoflist];
    std::vector<int> a{1,2,3,4,6,7,8,9,11};
    for (int it = 0; it < lengthoflist-1; ++it) {
        list[it].payload = it+1;
        
        list[it].next = &list[it + 1];
    }
    
    list[10].payload = 11;
    list[10].next = nullptr;
    testlist = list;
    deleteEveryFifthFromList(list, lengthoflist);

    for (int num = 0; num < a.size(); ++num) {
        ASSERT_EQ(a[num], list[num].payload);
    }

    ASSERT_EQ(list[7].next,testlist[9].next);
}

TEST(getMinAndMaxTest, zerotest){
    unsigned long a = 0;
    std::pair<unsigned long, unsigned long> ap = getMinAndMax(a);
    std::pair<unsigned long, unsigned long> testa{ 0, 0 };
    ASSERT_EQ(testa, ap);
}

TEST(getMinAndMaxTest, onetest) {
    unsigned long a = 1;
    std::pair<unsigned long, unsigned long> ap = getMinAndMax(a);
    std::pair<unsigned long, unsigned long> testa{ 1, pow(2,31) };
    ASSERT_EQ(testa, ap);
}

TEST(getMinAndMaxTest, commontest) {
    unsigned long a = 33;
    std::pair<unsigned long, unsigned long> ap = getMinAndMax(a);
    std::pair<unsigned long, unsigned long> testa{ 3, pow(2,31)+pow(2,30) };
    ASSERT_EQ(testa, ap);
}

TEST(allPathsTest, zerotest) {
    TreeNode* node = NULL;
    std::vector<std::vector<TreeNode*> > a = allPaths(node,maxTreeDepth(node));
    std::vector<std::vector<TreeNode*> > b(NULL);
    ASSERT_EQ(b, a);

}

TEST(allPathsTest, onetest) {
    TreeNode* root = addTreeNode(NULL);
    std::vector<std::vector<TreeNode*> > a = allPaths(root, maxTreeDepth(root));
    std::vector<std::vector<TreeNode*> > b;
    b.push_back(std::vector<TreeNode*>{root});
    ASSERT_EQ(b, a);

}

TEST(allPathsTest, threetest) {
    TreeNode* root = addTreeNode(NULL);
    // create left leaf
    TreeNode* leftleaf1 = addTreeNode(root);
    // create rigth leaf
    TreeNode* rigthleaf1 = addTreeNode(root, RIGTH_CHILD);

    TreeNode* rigthleaf2a = addTreeNode(rigthleaf1, RIGTH_CHILD);
    // add left child to leftleaf1
    TreeNode* leftLeaf2 = addTreeNode(leftleaf1);
    //add rigth leaf to leftleaf1
    TreeNode* rigthleaf2 = addTreeNode(leftleaf1, RIGTH_CHILD);
    std::vector<std::vector<TreeNode*> > a = allPaths(root, maxTreeDepth(root));
    std::vector<std::vector<TreeNode*> > b;
    b.push_back(std::vector<TreeNode*>{root, leftleaf1, leftLeaf2});
    b.push_back(std::vector<TreeNode*>{root,leftleaf1 ,rigthleaf2 });
    b.push_back(std::vector<TreeNode*>{root,rigthleaf1 ,rigthleaf2a });
    ASSERT_EQ(b, a);

}

int main(int argc, char **argv) {
    
    //Tree

    std::cout<<"\n Tree start:"<<std::endl;
    TreeNode* root = addTreeNode(NULL);
    // create left leaf
    TreeNode* leftleaf1 = addTreeNode(root);
    // create rigth leaf
    TreeNode* rigthleaf1 = addTreeNode(root, RIGTH_CHILD);

    TreeNode* rigthleaf2a = addTreeNode(rigthleaf1, RIGTH_CHILD);
    // add left child to leftleaf1
    TreeNode* leftLeaf2 = addTreeNode(leftleaf1);
    //add rigth leaf to leftleaf1
    TreeNode* rigthleaf2 = addTreeNode(leftleaf1, RIGTH_CHILD);
    std::cout << "TREE is: ";
    showTree(root);
   

    std::cout << "depth of this tree: " << maxTreeDepth(root)<<std::endl;

    std::cout << "test path to obj:" << std::endl;

    std::vector<TreeNode*> leftleaf2path;

    //std::cout << "vector size = " << leftleaf2path.size() << std::endl;
    
    
    
    std::cout << "finish path to obj!" << std::endl;

    std::cout << "///////////////////////" << std::endl;
    printPaths(root);


    //paths of max depth
    std::cout << "max paths root" << std::endl;
    std::vector<std::vector<TreeNode*> > paths = allPaths(root, maxTreeDepth(root));

    showPaths(paths);

    std::cout << "finish!" << std::endl;

    

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
