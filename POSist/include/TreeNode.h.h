#include <vector>
#include <string>
using namespace std;

template <typename T>

class TreeNode{
	private:
	int NodeNo=-1;
	TreeNode<T>* GenesisNode;
	string genesisReferenceNodeId;

public:
    T data;
    vector <TreeNode<T>*> children;
    string nodeId;
	string referenceNodeId;
	vector<string> childReferenceNodeId;



	TreeNode<T>(T data){
		this->data=data;
		this->NodeNo=++NodeNo;
		for(int i=0;i<children.size();i++){
            this->children[i]=NULL;
		}

		this->referenceNodeId='\0';
		for(int i=0;i<children.size();i++){
            this->childReferenceNodeId[i]='\0';
		}


        this->genesisReferenceNodeId=genesisReferenceNodeId;
	}
	void SetGenesis(TreeNode<T>* node){
        GenesisNode=node;
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
