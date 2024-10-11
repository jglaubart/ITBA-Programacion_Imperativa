typedef struct queueCDT *queueADT;

typedef int elementType;

queueADT newQueue(void);

// Agrega un elemento al final de la cola
void queue(queueADT q, elementType n);

// Remueve un elemento del principio de la cola y lo deja en out
void dequeue(queueADT q, elementType *out);

void freeQueue(queueADT q);

int isEmpty(queueADT q);


void toBegin(queueADT q);
 
int hasNext(queueADT q);
 
elementType next(queueADT q);
