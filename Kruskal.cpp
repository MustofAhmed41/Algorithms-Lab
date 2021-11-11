#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector < pair < int , pair < int , int > > > edges;
vector < pair < int , pair < int , int > > > minimum_tree;
vector < vector <int> > vec(100);
int n,m;
int fathers[100];

int find(int x){
	if(fathers[x] == x){
		return x;
	}
	return find(fathers[x]);
}

void unite(int x, int y){
	int fx = find(x);
	int fy = find(y);
	fathers[fx] = fy;
}

void display(){
    int a ,b ,w;
    cout << "Node\t" << "Weight"<<endl;
    for(int i = 1 ; i <= n ; i++){
        vec[i] = vector<int>(n+1);
    }

    for(int i = 0 ; i < minimum_tree.size(); i++){
        a = edges[i].second.first;
		b = edges[i].second.second;
		w = edges[i].first;
		vec[a][b] = w;
		vec[b][a] = w;
		cout << "<" << a << "," << b << ">\t" <<  w << endl;
    }

      cout <<endl << "The output in matrix form is : " << endl << endl;

    for(int i = 1; i <= n; i++){
        for(int j=1 ; j <= n; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){

	for(int i=0;i<100;i++){
		fathers[i]=i;
	}

	int a,b,w;
	cout << "Enter total number of nodes : " ;
	cin >> n;
	cout << "Enter total number of edges : ";
	cin >> m;
	cout << "Enter the pair of nodes and edges weight" << endl << endl;

	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		edges.push_back(make_pair( w,make_pair(a,b) ) );
	}

	cout<<endl;

	int mst_weight = 0, mst_edges = 0;
	int	mst_ni = 0;

	sort(edges.begin(),edges.end());

    cout << "The matrix of output is : " << endl;
	while( ( mst_edges < n-1) || (mst_ni < m) ){

		a = edges[mst_ni].second.first;
		b = edges[mst_ni].second.second;
		w = edges[mst_ni].first;

		if( find(a) != find(b) ) {

			unite(a,b);

			mst_weight += w;

			minimum_tree.push_back(make_pair( w,make_pair(a,b) ) );
			mst_edges++;
		}

		mst_ni++;
	}

	display();
	cout<<"\nWeight of the MST is "<<mst_weight<<endl;

}

/*
7
9
1 2 4
7 2 2
6 2 3
6 5 1
5 3 20
4 3 6
1 4 7
2 5 2
2 3 1

*/
