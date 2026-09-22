#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAXSIZE 30100

struct Node {
    int u;
    Node *next;
};

struct Graph {
    vector<Node *> adj;
};

bool flag;
char vis[MAXSIZE];

Graph *make_graph(int);
void free_graph(Graph *, int);
void dfs(Graph *, int);
Node *make_node(int);
void push_back(Graph *, int, int);

int main() {
    int n, m, i, k, u, v;
    cin >> k;

    while (k--) {
        cin >> n >> m;

        Graph *grafo = make_graph(n + 1);  // Ajustado para evitar índices inválidos

        for (i = 0; i < m; ++i) {
            cin >> u >> v;
            push_back(grafo, u, v);
        }

        flag = false;
        memset(vis, 0, (n + 1) * sizeof(char));  // Resetando apenas o necessário

        for (i = 1; i <= n; ++i) {  // Corrigido para percorrer corretamente os vértices
            if (!vis[i])
                dfs(grafo, i);
            if (flag)
                break;
        }

        cout << (flag ? "SIM" : "NAO") << endl;

        free_graph(grafo, n + 1);  // Liberando memória do grafo
    }

    return 0;
}

Graph *make_graph(int size) {
    Graph *graph = new Graph;
    graph->adj.resize(size, nullptr);
    return graph;
}

void free_graph(Graph *graph, int size) {
    for (int i = 0; i < size; ++i) {
        Node *current = graph->adj[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete graph;
}

Node *make_node(int u) {
    Node *new_node = new Node;
    new_node->u = u;
    new_node->next = nullptr;
    return new_node;
}

void push_back(Graph *graph, int u, int v) {
    Node *new_node = make_node(v);
    new_node->next = graph->adj[u];
    graph->adj[u] = new_node;
}

void dfs(Graph *graph, int u) {
    vis[u] = 1;

    if (flag)
        return;

    for (Node *i = graph->adj[u]; i != nullptr; i = i->next) {
        int v = i->u;
        if (vis[v] == 1) {
            flag = true;
            return;
        } else if (vis[v] == 0) {
            dfs(graph, v);
        }
    }

    vis[u] = 2;
}
