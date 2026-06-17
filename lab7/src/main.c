#include "lib/topologicalSort.h"

int main(void) {
    int n, m;

    if (scanf("%d", &n) != 1) {
        printf("bad number of lines");
        return 0;
    }
    if (n < 0 || n > 2000) {
        printf("bad number of vertices");
        return 0;
    }

    if (scanf("%d", &m) != 1) {
        printf("bad number of lines");
        return 0;
    }
    if (m < 0 || m > (long long) n * (n - 1) / 2) {
        printf("bad number of edges");
        return 0;
    }

    char *a = (char *) calloc((n + 1) * (n + 1), sizeof(char));

    for (int i = 0; i < m; i++) {
        int v, u;
        if (scanf("%d %d", &v, &u) != 2) {
            printf("bad number of lines");
            free(a);
            return 0;
        }
        if (v < 1 || v > n || u < 1 || u > n) {
            printf("bad vertex");
            free(a);
            return 0;
        }

        a[v * (n + 1) + u] = 1;
    }

    TopoSort(n, a);

    free(a);
    return EXIT_SUCCESS;
}
