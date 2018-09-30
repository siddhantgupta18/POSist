#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "TreeNode.h.h"
using namespace std;


void PrintLevelWise(TreeNode <string>* root){
	queue <TreeNode<string>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		TreeNode<string>* Front = pendingNodes.front();
		pendingNodes.pop();
		cout<<Front->data<<" : ";
		if(Front->children.size() !=NULL){
                for(int c=0;c<Front->children.size()-1;c++){
                    cout<<Front->children[c]->data<<", ";
                    pendingNodes.push(Front->children[c]);
                }

		}
		cout<<endl;
	}
}

void TakeInputLevelWise(TreeNode<string>* root){
    queue<TreeNode<string>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<string>* Front= pendingNodes.front();
        pendingNodes.pop();
        char p;
        cout<<"Is there any child of (Enter your answer in y/n):  "<<root->data<<endl;
        cin>>p;
        int i=0;
    //vector<TreeNode<string>*> children;
        while(p=='y'){
                string child_data;
                cout<<"Enter's Child Data"<<endl;
        getline(cin,child_data);
                    TreeNode<string>* child(child_data);


                    Front->children.push_back(child);
                    string x="child";
                    string NodeId=(Front->nodeId);
                    NodeId+=x;
                    NodeId+=i;
                    child->nodeId= NodeId;
                    Front->childReferenceNodeId.push_back(child->nodeId);
                    child->referenceNodeId=Front->nodeId;
                    cout<<"Enter data"<<endl;
                    cin>>child->data;
                    pendingNodes.push(child);
                    cin>>p;
                    i++;
        }
    }



}


int main() {
	// your code goes here
	cout<<"Give data Level Wise "<<endl;
	string root_data;
	cout<<"Enter Root's Data "<<endl;
	getline(cin,root_data);
	TreeNode<string>* root=new TreeNode<string>(root_data) ;
	root->SetGenesis(root);
	TakeInputLevelWise(root);
	PrintLevelWise(root);
	return 0;
}
