
#include"list.h"
#include"pairheap.h"
#include<time.h>
#include<limits.h>

typedef struct  {
	int vindex;
	BOOL known;
	ValueType dist;
	int preindex;
}TableLine;

typedef struct {
	int vindex;
	LinkedList neighbours;
} Adjancent;

char *vertexName[] = { "V1", "V2", "V3", "V4", "V5", "V6", "V7" };

void InitResultTable(TableLine resultTable[],int len){
	int i;
	for(i=0;i<len;i++){
		resultTable[i].vindex=i;
		resultTable[i].known=FALSE;
		resultTable[i].dist=INT_MAX;
		resultTable[i].preindex=-1;
	}
}

/*根据最终的TableLine打印到各节点的最短路径*/
void printShortWay(TableLine resultTable[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("%s: ",vertexName[resultTable[i].vindex]);
		double way=resultTable[i].dist;
		int curline=i;
		do{
			int p=resultTable[curline].preindex;
			if(p!=-1)
				printf("%s\t",vertexName[p]);
			//else
			//printf("END\t");
		}while((curline=resultTable[curline].preindex)!=-1);
		printf("总路程:%d\n",(int)way);
	}
}

/*初始化带权有向图*/
void InitGraph(Adjancent **graph)
{
	LinkedList *list0;list0=(LinkedList *)malloc(sizeof(LinkedList));Initialize_L(list0);
	Item item1;item1.vindex=1;item1.dist=2;Insert_L(list0, item1);
	Item item2;item2.vindex=3;item2.dist=1;Insert_L(list0, item2);
	Adjancent *adj0;adj0=(Adjancent *)malloc(sizeof(Adjancent));adj0->vindex = 0;adj0->neighbours = *list0;graph[0]=adj0;

	LinkedList *list1;list1=(LinkedList *)malloc(sizeof(LinkedList));Initialize_L(list1);
	Item item3;item3.vindex=3;item3.dist=3;Insert_L(list1, item3);
	Item item4;item4.vindex=4;item4.dist=10;Insert_L(list1, item4);
	Adjancent *adj1;adj1=(Adjancent *)malloc(sizeof(Adjancent));adj1->vindex = 1;adj1->neighbours = *list1;graph[1]=adj1;

	LinkedList *list2;list2=(LinkedList *)malloc(sizeof(LinkedList));Initialize_L(list2);
	Item item5;item5.vindex=0;item5.dist=4;Insert_L(list2, item5);
	Item item6;item6.vindex=5;item6.dist=5;Insert_L(list2, item6);
	Adjancent *adj2;adj2=(Adjancent *)malloc(sizeof(Adjancent));adj2->vindex = 2;adj2->neighbours = *list2;graph[2]=adj2;

	LinkedList *list3;list3=(LinkedList *)malloc(sizeof(LinkedList));Initialize_L(list3);
	Item item7;item7.vindex=2;item7.dist=2;Insert_L(list3, item7);
	Item item8;item8.vindex=4;item8.dist=2;Insert_L(list3, item8);
	Item item9;item9.vindex=5;item9.dist=8;Insert_L(list3, item9);
	Item item10;item10.vindex=6;item10.dist=4;Insert_L(list3, item10);
	Adjancent *adj3;adj3=(Adjancent *)malloc(sizeof(Adjancent));adj3->vindex = 3;adj3->neighbours = *list3;graph[3]=adj3;

	LinkedList *list4;list4=(LinkedList *)malloc(sizeof(LinkedList));Initialize_L(list4);
	Item item11;item11.vindex=6;item11.dist=6;Insert_L(list4, item11);
	Adjancent *adj4;adj4=(Adjancent *)malloc(sizeof(Adjancent));adj4->vindex = 4;adj4->neighbours = *list4;graph[4]=adj4;

	LinkedList *list5;list5=(LinkedList *)malloc(sizeof(LinkedList));Initialize_L(list5);
	Adjancent *adj5;adj5=(Adjancent *)malloc(sizeof(Adjancent));adj5->vindex = 5;adj5->neighbours = *list5;graph[5]=adj5;

	LinkedList *list6;list6=(LinkedList *)malloc(sizeof(LinkedList));Initialize_L(list6);
	Item item12;item12.vindex=5;item12.dist=1;Insert_L(list6, item12);
	Adjancent *adj6;adj6=(Adjancent *)malloc(sizeof(Adjancent));adj6->vindex = 6;adj6->neighbours = *list6;graph[6]=adj6;
}

/*以领接表的形式打开带权有向图*/
void printGraph(Adjancent **graph){
	int i, j;
	LTNode *neighbour;
	for (i = 0; i < VERTEXNUM; i++) {
		printf("%s\t", vertexName[graph[i]->vindex]);
		neighbour = graph[i]->neighbours->head;
		int len = graph[i]->neighbours->size;
		while (len-- > 0) {
			printf("%s(%d)\t", vertexName[neighbour->item.vindex],
					(int)(neighbour->item.dist));
			neighbour = neighbour->next;
		}
		printf("\n");
	}
}

int main()
{
	Adjancent **graph;
	graph = (Adjancent **) malloc(sizeof(Adjancent *) * VERTEXNUM);
	InitGraph(graph);
	printGraph(graph);

	TableLine resultTable[VERTEXNUM];
	InitResultTable(resultTable,VERTEXNUM);

	PairingHeap * pph;
	pph=(PairingHeap *)malloc(sizeof(PairingHeap));
	Initialize_P(pph);

	int startindex=0;       /*指定起点*/
	resultTable[startindex].dist=0;

	int i;
	for(i=0;i<VERTEXNUM;++i){
		Item item;
		item.vindex=i;
		if(i!=startindex)
			item.dist=INT_MAX;
		else
			item.dist=0;
		Insert_P(pph,item);
	}
	//printf("初始化堆后： ");
	//Print_P(pph);

	while(1){
		Item *pmin;
		pmin=(Item*)malloc(sizeof(Item));
		if(DeleteMin_P(pph,pmin)==FALSE){       /*从配对堆上取下最小元素*/
			break;
		}
		//printf("取下最小元素后： ");
		//Print_P(pph);
		int index=pmin->vindex;
		resultTable[index].known=TRUE;
		double cvw=resultTable[index].dist;
		LTNode *neighbour= graph[index]->neighbours->head;
		int len = graph[index]->neighbours->size;
		while (len-- > 0) {
			int ind=neighbour->item.vindex;
			if(resultTable[ind].known==FALSE){
				double d=neighbour->item.dist;
				if(d+cvw<resultTable[ind].dist){
					Item fi;
					fi.vindex=ind;
					fi.dist=resultTable[ind].dist;
					PHNode *change=Find_P(pph,fi);
					if(change==NULL){
						fprintf(stderr,"在配对堆上找不到要找的项.vindex=%d\tdist=%d\n",fi.vindex,(int)fi.dist);
						free(change);
						exit(1);
					}
					//printf("change:vindex=%d\tdist=%d\n",change->item.vindex,(int)change->item.dist);
					DecreaseKey_P(pph,change,resultTable[ind].dist-d-cvw);
					//printf("降低元素值后： ");
					//Print_P(pph);
					resultTable[ind].dist=d+cvw;
					resultTable[ind].preindex=index;
				}
			}
			neighbour = neighbour->next;
		}
	}

	printShortWay(resultTable,VERTEXNUM);
	Release_P(pph);
	for(i=0;i<VERTEXNUM;++i){
		Release_L(&(graph[i]->neighbours));
	}
	return 0;
}
