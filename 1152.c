#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} vertex;

#define MAXSIZE 200100 

vertex g[MAXSIZE];
int p[MAXSIZE], rank[MAXSIZE];

int kruskal(int);
int find(int);
void union_set(int, int);
int compara(const void *, const void *);

int main() {
    int e, v;

    while (scanf("%d %d", &e, &v), e && v) {
        int i;
        unsigned total = 0;
        
        for (i = 0; i < v; ++i) {
            scanf("%d %d %d", &g[i].v, &g[i].u, &g[i].w);
            total += g[i].w;
        }

        qsort(g, v, sizeof(vertex), compara);

        for (i = 0; i <= e; ++i) {
            p[i] = i;
            rank[i] = 0;  // Inicializando rank
        }

        printf("%u\n", total - kruskal(v));
    }

    return 0;
}

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]); // Compressão de caminho
    return p[x];
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a != b) {
        if (rank[a] > rank[b]) {
            p[b] = a;
        } else {
            p[a] = b;
            if (rank[a] == rank[b])
                rank[b]++;
        }
    }
}

int kruskal(int __c) {
    int i, u, v;
    unsigned ans = 0;

    for (i = 0; i < __c; ++i) {
        v = find(g[i].v);
        u = find(g[i].u);

        if (u != v) {
            union_set(u, v);
            ans += g[i].w;
        }
    }

    return ans;
}

int compara(const void *a, const void *b) {
    return ((vertex*)a)->w - ((vertex*)b)->w;
}
