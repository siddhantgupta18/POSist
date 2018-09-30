#include <vector>
#include <string>
using namespace std;

template <typename T>

class TreeNode{
	private:
	T data;
	int NodeNo=-1;
	string nodeId;
	string referenceNodeId;
	vector<string> childReferenceNodeId;
	string genesisReferenceNodeId;
	TreeNode<T>* GenesisNode;
	vector<TreeNode<T>*> children;

public:
	TreeNode<T>(T data){
		this->data=data;
		this->NodeNo=++NodeNo;
		this->children=NULL;
		this->referenceNodeId='\0';
        this->childReferenceNodeId='\0';
        this->genesisReferenceNodeId=genesisReferenceNodeId;
	}
	void setGenesis(TreeNode<T>* root){
        GenesisNode=root;
        genesisReferenceNodeId="parent_node" ;
        GenesisNode->referenceNodeId="start";
        GenesisNode->nodeId=genesisReferenceNodeId;
	}

	/*~TreeNode<T> {
	    for(int i=0;i<children.size();i++){
            delete children[i];
	    }

	}*/


};
