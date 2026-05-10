#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          iData;
    struct Node* pNext;
} Node;

typedef struct
{
    Node*  pHead;
    size_t n;
} CircularList;

void InitList( CircularList* pList )
{
    pList->pHead = NULL;
    pList->n = 0;
}

void FreeList( CircularList* pList )
{
    if ( pList->pHead == NULL )
        return;
    
    Node* pCurrent = pList->pHead;
    Node* pTemp;
    
    // Break the circular link by traversing to the last node
    Node* pLast = pList->pHead;
    while ( pLast->pNext != pList->pHead )
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = NULL; // Break the circle
    
    // Now free all nodes
    while ( pCurrent != NULL )
    {
        pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free( pTemp );
    }
    
    pList->pHead = NULL;
    pList->n = 0;
}

void InsertEnd( CircularList* pList, const int iValue )
{
    Node* pNewNode = (Node*)malloc( sizeof(Node) );
    pNewNode->iData = iValue;
    
    if ( pList->pHead == NULL )
    {
        // Empty list: node points to itself
        pNewNode->pNext = pNewNode;
        pList->pHead = pNewNode;
    }
    else
    {
        // Find the last node (the one pointing to head)
        Node* pLast = pList->pHead;
        while ( pLast->pNext != pList->pHead )
        {
            pLast = pLast->pNext;
        }
        
        // Insert new node at the end
        pLast->pNext = pNewNode;
        pNewNode->pNext = pList->pHead;
    }
    
    pList->n++;
}

float ComputeAverage( const CircularList* pList )
{
    if ( pList->n == 0 )
        return 0.0f;
    
    int sum = 0;
    Node* pCurrent = pList->pHead;
    
    // Traverse exactly once
    for ( size_t i = 0; i < pList->n; i++ )
    {
        sum += pCurrent->iData;
        pCurrent = pCurrent->pNext;
    }
    
    return (float)sum / (float)pList->n;
}

size_t DeleteLt( CircularList* pList, const int iValue )
{
    if ( pList->pHead == NULL )
        return 0;
    
    size_t deletedCount = 0;
    Node* pCurrent = pList->pHead;
    Node* pPrev = NULL;
    Node* pTemp;
    
    // Find the last node to use as initial previous
    Node* pLast = pList->pHead;
    while ( pLast->pNext != pList->pHead )
    {
        pLast = pLast->pNext;
    }
    
    pPrev = pLast;
    size_t nodesToCheck = pList->n;
    
    for ( size_t i = 0; i < nodesToCheck; i++ )
    {
        if ( pCurrent->iData < iValue )
        {
            pTemp = pCurrent;
            
            if ( pCurrent == pList->pHead )
            {
                // Deleting head node
                if ( pList->n == 1 )
                {
                    // Only one node in the list
                    pList->pHead = NULL;
                }
                else
                {
                    pList->pHead = pCurrent->pNext;
                    pPrev->pNext = pList->pHead;
                }
            }
            else
            {
                pPrev->pNext = pCurrent->pNext;
            }
            
            pCurrent = pCurrent->pNext;
            free( pTemp );
            deletedCount++;
            pList->n--;
        }
        else
        {
            pPrev = pCurrent;
            pCurrent = pCurrent->pNext;
        }
    }
    
    return deletedCount;
}
