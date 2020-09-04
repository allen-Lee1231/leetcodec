#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* pnPre;
    int* pnIn;
    int length;
    int preLen;
    int inLen;
} CQueue;


CQueue* cQueueCreate() {
    int* pnPre = (int*) malloc(sizeof(int) * 10000);
    int* pnIn = (int*) malloc(sizeof(int) * 10000);
    CQueue *BUFFER = (CQueue*) malloc(sizeof(CQueue));
    BUFFER->pnPre = pnPre;
    BUFFER->pnIn = pnIn;
    BUFFER->length = 0;
    BUFFER->preLen = 0;
    BUFFER->inLen = 0;
    return BUFFER;
}

void cQueueAppendTail(CQueue* obj, int value) {
    obj->pnPre[obj->preLen] = value;
    obj->length ++;
    obj->preLen ++;
}

int cQueueDeleteHead(CQueue* obj) {
    if (obj->length < 1)
    {
        return -1;
    }

    int preIdx = obj->preLen - 1;
    if (obj->inLen == 0)
    {
        for (int i=0; i<=preIdx; i++)
        {
            obj->pnIn[i] = obj->pnPre[preIdx - i];
        }
        obj->inLen = preIdx;
        obj->preLen = 0;
    }
    else
    {
        obj->inLen--;
    }

    obj->length --;
    return obj->pnIn[obj->inLen];
}

void cQueueFree(CQueue* obj) {
    free(obj->pnPre);
    free(obj->pnIn);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);

 * int param_2 = cQueueDeleteHead(obj);

 * cQueueFree(obj);
*/

int main()
{
    CQueue* cqTest = cQueueCreate();
    cQueueAppendTail(cqTest, 5);
    printf("deleted head value: %d\n", cQueueDeleteHead(cqTest));
    printf("deleted head value: %d\n", cQueueDeleteHead(cqTest));
    cQueueAppendTail(cqTest, 3);
    cQueueAppendTail(cqTest, 9);
    printf("deleted head value: %d\n", cQueueDeleteHead(cqTest));
    cQueueAppendTail(cqTest, 11);
    printf("deleted head value: %d\n", cQueueDeleteHead(cqTest));
    printf("deleted head value: %d\n", cQueueDeleteHead(cqTest));
    cQueueFree(cqTest);
}