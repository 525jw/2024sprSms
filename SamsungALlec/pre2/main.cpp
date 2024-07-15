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
#include <set>
#include <map>
using namespace std;
vector<set<int>> adjlist;

void init(int N)
{
	adjlist.clear();
    adjlist.resize(N+1,set<int>());
}

void add(int id, int F, int ids[MAXF])
{
    for(int i=0;i<F;i++){
        adjlist[id].insert(ids[i]);
		adjlist[ids[i]].insert(id);
    }
}

void del(int id1, int id2)
{
    adjlist[id1].erase(id2);
	adjlist[id2].erase(id1);
}

int recommend(int id, int list[MAXL])
{   
    map<int,int> cntmap;
    for(auto frnd=adjlist[id].begin();frnd!=adjlist[id].end();frnd++){
        for(auto rcmd=adjlist[*frnd].begin();rcmd!=adjlist[*frnd].end();rcmd++){
            if(*frnd==*rcmd || adjlist[*rcmd].find(*frnd)!=adjlist[*rcmd].end())
                continue;
            else{
                if(cntmap.find(*rcmd))
            }s
        }
    }
    int count=0;
    for(int i=0;i<5;i++){

    }
    return count;
}