#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
   string item;       // The data in this node.
   TreeNode *left;    // Pointer to left subtree.
   TreeNode *right;   // Pointer to right subtree.
   TreeNode *parent;
   TreeNode(string str = "") {
          // Constructor, defined for convenience. 
          // Make a node containing the specified string.
      item = str;
      left = NULL;
      right = NULL;
	  parent = NULL;
   }
};  // end struct TreeNode


void treeInsertLeft(TreeNode *&node, string newItem) {
       // Add the item to the binary sort tree to which the parameter
       // "root" refers.  Note that root is passed by reference since
       // its value can change in the case where the tree is empty.
   
          // The tree is empty.  Set root to point to a new node containing
          // the new item.  This becomes the only node in the tree.
      node->left = new TreeNode( newItem );
	  //node->left->parent = node;
      return;
   
   
}  // end treeInsert()

void treeInsertRight(TreeNode *&node, string newItem) {
       // Add the item to the binary sort tree to which the parameter
       // "root" refers.  Note that root is passed by reference since
       // its value can change in the case where the tree is empty.
   
          // The tree is empty.  Set root to point to a new node containing
          // the new item.  This becomes the only node in the tree.
      node->right = new TreeNode( newItem );
	  //node->right->parent = node;
      return;
   
   
}  // end treeInsert()

void treeInsert(TreeNode *&node, string newItem) {
       // Add the item to the binary sort tree to which the parameter
       // "root" refers.  Note that root is passed by reference since
       // its value can change in the case where the tree is empty.
   
          // The tree is empty.  Set root to point to a new node containing
          // the new item.  This becomes the only node in the tree.
      //if(node->parent != NULL)
	  //{
	  //TreeNode *treeNodeParent = node->parent;
	  node = new TreeNode( newItem );
	  //node->parent = treeNodeParent;
	 // }
	 // else
	//	  node = new TreeNode( newItem );
      return;
   
   
}  // end treeInsert()


bool treeContains( TreeNode *root, string item ) {
       // Return true if item is one of the items in the binary
       // sort tree to which root points.   Return false if not.
   if ( root == NULL ) {
         // Tree is empty, so it certainly doesn't contain item.
      return false;
   }
   else if ( item == root->item ) {
         // Yes, the item has been found in the root node.
      return true;
   }
   else if ( item < root->item ) {
         // If the item occurs, it must be in the left subtree.
      return treeContains( root->left, item );
   }
   else {
         // If the item occurs, it must be in the right subtree.
      return treeContains( root->right, item );
   }
}  // end treeContains()


//Print item in node
void printNode(TreeNode *node) {
	if ( node != NULL )
         cout << node->item << endl;
   }


int countNodes(TreeNode *node) {
      // Count the nodes in the binary tree to which node 
      // points.  Return the answer.
   if ( node == NULL ) {
           // Tree is empty, so it contains no nodes.
      return 0;
   }
   else {
          // Add up the root node and the nodes in its two subtrees.
      int leftCount = countNodes( node->left );
      int rightCount = countNodes( node->right );
      return  1 + leftCount + rightCount;  
   }
} // end countNodes()


void buildSystem();
void guess(TreeNode *node);
void traverse(TreeNode *node);


	TreeNode *root = NULL;  // Pointer to the root node in a binary tree.  This
                    // tree is used in this program as a binary sort tree.
                    // The tree is not allowed to contain duplicate
                    // items.  When the tree is empty, root is null.

	 // Start with an empty tree.
	int userChoice = 1;
	bool expertSystem = false;
	string treeFile, userQuestion, userItem, userQA;
	char userAnswer;
	int question = 0;
	int question2 = 0;


int main() {

   treeInsert(root, "Do you want to play 20 questions?");
   treeInsertLeft(root, "Whale");
   treeInsertRight(root, "Goodbye");

   cout << "20 Questions" << endl << endl;
	
	while(userChoice)
	{
		cout << "1. Build an Expert System" << endl;
		cout << "2. Play 20 questions" << endl;
		cout << "3. Quit" << endl;
		cout << "Please choose one:  ";
		cin >> userChoice;
		while(userChoice != 1 && userChoice != 2 && userChoice != 3)
		{
			cout << "Invalid response. Try again:  ";
			cin >> userChoice;
		}

		if(userChoice == 1)
		{			
			buildSystem();
			//BuildTree();
			expertSystem = true;
		}

		if(userChoice == 2)
		{
			if(!expertSystem)
			{
				cout << "You do not have an expert system yet." << endl;
				cout << "Please enter a file containing a decision tree:  ";
				cin >> treeFile;
				//BuildTree();
			}
			
				//TwentyQuestions();
		}
		
		if(userChoice == 3)
		{
			cout << "Thanks for playing!" << endl;
			exit(1);
		}
	}
   
   cout << "This programs stores strings that you enter in a binary sort\n";
   cout << "tree.  After each items is inserted, the contents of the tree\n";
   cout << "are displayed.  The number of nodes in the tree is also output.\n";
   cout << "    Any string you enter will be converted to lower case.\n";
   cout << "Duplicate entries are ignored.\n";

   while (true) {
           // Get one string from the user, insert it into the tree,
           // and print some information about the tree.  Exit if the
           // user enters an empty string.  Note that all strings are
           // converted to lower case.
       cout << ("\n\nEnter a string to be inserted, or press return to end.\n");
       cout << ("?  ");
       string item;  // The user's input.
       if (cin.peek() == '\n')
          break;
       cin >> item; 
       cin.ignore(10000,'\n');
       if (treeContains(root,item)) {
              // Don't insert a second copy of an item that is already
              // in the tree.
          cout << "\nThat item is already in the tree.\n";
       }
       else {
          treeInsert(root,item);  // Add user's string to the tree.
          cout << "\nThe tree contains " << countNodes(root) << " items.\n";
          cout << "\nContents of tree:\n\n";
          printNode(root);
       }
   }  // end while

   cout << "\n\nExiting program.\n\n";

}

void buildSystem()
{
	cout << endl << "Let's build an expert system decision tree!" << endl;
	printNode(root);
	question++;
	cin >> userAnswer;
	while(userAnswer != 'Y' && userAnswer != 'y' && userAnswer != 'N' && userAnswer != 'n')
	{
		cout << "Invalid response. Try again:  ";
		cin >> userAnswer;
	}
	if(userAnswer == 'Y' || userAnswer == 'y')
	{
		if(root->left)
		{
			TreeNode *curTreeNode = root->left;			
			if(curTreeNode->left)
				traverse(curTreeNode);
			else
				guess(curTreeNode);
		}
	}
	else
	{
		printNode(root->right);
		exit(1);
	}
}

void guess(TreeNode *node)
{
	cout << "I guess you are thinking of " << node->item << "." << endl;
	cout << "Is my guess correct?  ";
	cin >> userAnswer;
	while(userAnswer != 'Y' && userAnswer != 'y' && userAnswer != 'N' && userAnswer != 'n')
	{
		cout << "Invalid response. Try again:  ";
		cin >> userAnswer;
	}
	if(userAnswer == 'Y' || userAnswer == 'y')
	{
		cout << "Thanks for playing. I guessed your item in " << question << " number of questions." << endl << endl;
	}
	else
	{
		cout << "Please tell me what you are thinking of:  ";
		cin >> userItem;
		cin.ignore();
		cout << "Please give me a question that can distinguish between " << node->item << " and " << userItem << "." << endl;
		getline(cin, userQuestion);
		cout << "For " << userItem << " what would the answer to this question be?" << endl;
		cin >> userQA;
		while(userQA != "Yes" && userQA != "yes" && userQA != "No" && userQA != "no")
		{
			cout << "Invalid response. Try again:  ";
			cin >> userQA;
		}
		if(userQA == "Yes" || userQA == "yes")
		{
			cout << node->item << endl;
			TreeNode *curTreeNode = node;
			//TreeNode *curTreeNode2 = new TreeNode(userItem);
			TreeNode *treeNodeParent = node->parent;
			treeInsert(node, userQuestion);
			node->parent = treeNodeParent;
			treeInsertRight(node, curTreeNode->item);
			node->right->parent = node;
			treeInsertLeft(node, userItem);
			node->left->parent = node;
			//node->right = node;
			//node->left = curTreeNode2;
			//node = curTreeNode;
			cout << node->item << endl;
			
		}
		else
		{
			
			TreeNode *curTreeNode = node;
			TreeNode *treeNodeParent = node->parent;
			treeInsert(node, userQuestion);
			node->parent = treeNodeParent;
			treeInsertLeft(node, curTreeNode->item);
			node->left->parent = node;
			treeInsertRight(node, userItem);
			node->right->parent = node;
			
			//cout << node->left->item << " " << node->item << " " << node->right->item << endl;
		}

		if(question < 5)
			buildSystem();

		
	}
}

void traverse(TreeNode *node)
{
	printNode(node);
	question++;
	cin >> userAnswer;
	while(userAnswer != 'Y' && userAnswer != 'y' && userAnswer != 'N' && userAnswer != 'n')
	{
		cout << "Invalid response. Try again:  ";
		cin >> userAnswer;
	}
	if(userAnswer == 'Y' || userAnswer == 'y')
	{
		if(node->left)
		{
			TreeNode *curTreeNode = node->left;			
			if(curTreeNode->left)
				traverse(curTreeNode->left);
			else
				guess(curTreeNode);
		}
	}
	else
	{
		guess(node->right);
	}
}


