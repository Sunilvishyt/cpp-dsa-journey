//Adjacency matrix
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertex, edges;
    cout << "Enter Vertex and Edges eg. 5 5 : ";
    cin >> vertex >> edges;
    vector<vector<int>>AdjMatrix(vertex, vector<int>(vertex, 0));

    cout << "Enter all edge connections eg. 0 1 (means 0 node is connected to 1) : " << endl;
    int u, v;
    for (int i = 0; i < edges; i++){
        cin >> u >> v;
        AdjMatrix[u][v] = 1;
        AdjMatrix[v][u] = 1;
    }

    //print
    cout << endl;
    cout << endl;
    cout << "Adjacency Matrix ----" << endl;
    for (int i = 0; i < vertex; i++){
        for (int j = 0 ; j < vertex; j++){
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}

//Adjacency List

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertex, edges;
    cout << "Enter Vertex and Edges eg. 5 5 : ";
    cin >> vertex >> edges;
    vector<int>AdjList[vertex];

    cout << "Enter all edge connections eg. 0 1 (means 0 node is connected to 1) : " << endl;
    int u, v;
    for (int i = 0; i < edges; i++){
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    //print
    cout << endl;
    cout << endl;
    cout << "Adjacency List ----" << endl;
    for (int i = 0; i < vertex; i++){
        cout << i << " --> ";
        for (int j = 0 ; j < AdjList[i].size(); j++){
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}
