#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define	MAXL			5
#define MAXF			10

extern void init(int N);
extern void add(int id, int F, int ids[MAXF]);
extern void del(int id1, int id2);
extern int  recommend(int id, int list[MAXL]);

#define INIT			1
#define ADD				2
#define DEL				3
#define RECOMMEND		4

static int N, M;

static bool run()
{
	int cmd;
	int id, F, ids[MAXF];
	int id1, id2;
	int len, len_a;
	int list[MAXL], list_a[MAXL];
	
	bool okay;

	okay = false;

	scanf("%d", &M);

	for (int k = 0; k < M; ++k)
	{
		scanf("%d", &cmd);
		switch(cmd)
		{
		case INIT:
			scanf("%d", &N);
			init(N);
			okay = true;
			break;
		case ADD:
			scanf("%d %d", &id, &F);
			for (int i = 0; i < F; ++i)
				scanf("%d", &ids[i]);
			if (okay)
				add(id, F, ids);
			break;
		case DEL:
			scanf("%d %d", &id1, &id2);
			if (okay)
				del(id1, id2);
			break;
		case RECOMMEND:
			scanf("%d %d", &id, &len_a);
			for (int i = 0; i < len_a; ++i)
				scanf("%d", &list_a[i]);
			if (okay)
			{
				len = recommend(id, list);
				if (len != len_a)
					okay = false;

				for (int i = 0; okay && i < len_a; ++i)
					if (list[i] != list_a[i])
						okay = false;
			}
			break;
		}
	}
	
	return okay;
}

int main()
{
	int TC, MARK;
	
    freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);
    scanf("%d %d", &TC, &MARK);

    for (int testcase = 1; testcase <= TC; ++testcase)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", testcase, score);
    }

    return 0;
}

//USER CODE
#define MAXL	5
#define MAXF	10
#include <vector>
#include <queue>
using namespace std;
vector<vector<bool>> adjmat;

void init(int N)
{
	adjmat.clear();
    adjmat.resize(N+1,vector<bool>(N+1,false));
}

void add(int id, int F, int ids[MAXF])
{
    for(int i=0;i<F;i++){
        adjmat[id][ids[i]]=true;
		adjmat[ids[i]][id]=true;
    }
}

void del(int id1, int id2)
{
    adjmat[id1][id2]=false;
	adjmat[id2][id1]=false;
}

int recommend(int id, int list[MAXL])
{   
    priority_queue< pair<int,int> , vector< pair<int,int> > , less< pair<int, int> > > pq;
    int i,j,friendNum;
	int N=adjmat.size()-1;
    for(i=1;i<=N;i++){
		if(id==i || adjmat[id][i]==true)
            continue;
        friendNum=0;
        for(j=1;j<=N;j++){
            if(adjmat[id][j]==true && adjmat[i][j]==true)
                friendNum++;
        }
		if(friendNum>0){
        	pq.push(make_pair(friendNum,-i));
		}
    }

    int count = 0;
    while (!pq.empty() && count < MAXL) {
        list[count++] = -pq.top().second;
        pq.pop();
    }

    return count;
}