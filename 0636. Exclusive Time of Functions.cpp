#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {

    int* ans = (int*)calloc(n, sizeof(int));
    int stack[logsSize];
    int top = -1;

    int prevTime = 0;

    for (int i = 0; i < logsSize; i++) {

        int id, time;
        char type[10];

        sscanf(logs[i], "%d:%[^:]:%d", &id, type, &time);

        if (strcmp(type, "start") == 0) {

            // Give time to currently running function
            if (top != -1) {
                ans[stack[top]] += time - prevTime;
            }

            // Start new function
            stack[++top] = id;
            prevTime = time;
        }

        else {

            // Current function ends
            ans[stack[top]] += time - prevTime + 1;

            top--;

            // Next execution starts after this timestamp
            prevTime = time + 1;
        }
    }

    *returnSize = n;

    return ans;
}
