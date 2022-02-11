#include<iostream> 
#include<list>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

struct vertexlist
{
	struct node *vlisthead;
};

struct graph
{
	int v;
	struct vertexlist *vl; 
};

struct graph* creategraph(int n)
{
	int i;
	struct graph *vlist = new graph;
	vlist->v = n;
 
	vlist->vl = new vertexlist[n+1];
 
	for(i = 0; i < n+1; i++)
	{
		vlist->vl[i].vlisthead = NULL;
	}
 
	return vlist;
}

struct node* newnode(int value)
{
	struct node *newnode = new node;
	newnode->data = value;
	newnode->link = NULL;
 
	return newnode;
}

void InsertNode(graph *G, int v1, int v2)
{
	node *newnode1 = newnode(v1);
	node *newnode2 = newnode(v2);
	node *temp = new node;
	
    if(G->vl[v2].vlisthead == NULL)
	{
		G->vl[v2].vlisthead = newnode1;
	}
	else
	{
		newnode1->link = G->vl[v2].vlisthead;
		G->vl[v2].vlisthead = newnode1;
	}
	
	if(G->vl[v1].vlisthead == NULL)
	{
		G->vl[v1].vlisthead = newnode2;
	}
	else
	{
		newnode2->link = G->vl[v1].vlisthead;
		G->vl[v1].vlisthead = newnode2;
	}
}
void BFS(int startVertex, int numVertices,graph *G) {
    bool visited[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;

    visited[startVertex-1] = true;
    queue.push_back(startVertex-1);

    list<int>::iterator i;

    while (!queue.empty()) {
        int currVertex = queue.front();
        cout << currVertex+1 << "->";
        queue.pop_front();

        for (i = G->vl->vlisthead; i != G->vl[numVertices].vlistheaddata; ++i) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}
 
int main()
{
	int i, v, e;
 
	cout<<"Enter the number of vertexes of the graph: ";
	cin>>v;
	struct graph *G = creategraph(v);
	cout<<"\nEnter the number of edges of the graph: ";
	cin>>e;
	int edge[e][2];
 
	for(i = 0; i < e; i++)
	{
		cout<<"\nEnter the vertex pair for edge "<<i+1;
		cout<<"\nV(1): ";
		cin>>edge[i][0];
		cout<<"V(2): ";
		cin>>edge[i][1];
 
		InsertNode(G, edge[i][0], edge[i][1]);
	}
 
	cout<<"\n\nThe incidence list representation for the given graph: ";
	for(i = 0; i < v; i++)
	{
		cout<<"\n\tV("<<i+1<<") -> {  ";
		while(G->vl[i+1].vlisthead != NULL)
		{
			cout<<G->vl[i+1].vlisthead->data<<"  ";
			G->vl[i+1].vlisthead = G->vl[i+1].vlisthead->link;
		}
		cout<<"}";
	}
}
