#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#define CMD_INIT		(100)
#define CMD_ADD			(200)
#define CMD_ERASE		(300)
#define CMD_FIND		(400)
#define CMD_GET_INDEX	(500)

#define MAX_N			(30000)
#define MAX_L			(8)
#define rint register int

struct RESULT
{
	int success;
	char word[MAX_L + 1];
};

// extern void init(int N, char mWordList[][MAX_L + 1]);
// extern int add(char mWord[]);
// extern int erase(char mWord[]);
// extern RESULT find(char mInitial, int mIndex);
// extern int getIndex(char mWord[]);
// void init(int N, char mWordList[][MAX_L + 1])
// {
// 	return;
// }

// int add(char mWord[])
// {
// 	return -1;
// }

// int erase(char mWord[])
// {
// 	return -1;
// }

// RESULT find(char mInitial, int mIndex)
// {
// 	RESULT res;

// 	res.success = -1;
// 	res.word[0] = '\0';

// 	return res;
// }

// int getIndex(char mWord[])
// {
// 	return -1;
// }

struct Trie;
Trie * get_node();
// Tre
struct Trie
{
    Trie *ch[26]; //child
    int is_end; // 단어의 끝을 나타낸다. 
    int cnt; // 현재 node 까지 word 수  예 ) 현재 node 가   root->['a']  인 경우 현재까지 단어중 'a' 로 시작하는 단어의 수를 나타낸다.
    // trie 에  word 등록 
    void add(char *str)
    {
        cnt++; // node 를 내려가면서  단어수를 하나 증가 시킨다. 
        if (*str == 0)
        {
            is_end = 1; // 끝인 경우 끝표시 
            return;
        }
        rint idx = *str - 'a'; // a..z => 0..26
        if (ch[idx] == 0)  ch[idx] = get_node();// 처음 만들어지는 노드에 메모리 pool 에서 할당 
        ch[idx]->add(str + 1); // 다음 문자로 이동 
    }
    // Trie 에서 str word 가 존재하는지 확인한다. 
    bool find(char *str)
    {
        if (*str == 0)
        {
            return is_end;  //  존재 유무
        }
        rint idx = *str - 'a';
        if (ch[idx] == 0) return false; //   노드를 내려 갈 수 없으면 없는 단어 이다. 
        return ch[idx]->find(str + 1); // 다음 문자 확인 
    }
    // Trie 구조에서 str word 삭제 실제 삭제가 아니고 
    // node tree 를 따라가면서  word cnt에서 하나빼주고 
    // 마지막 is_end 를 0 로 만든다. 
    // -- 반드시  find를 통해 존재하는 단어만 삭제해야 된다. 
    //
    void erase(char *str)
    {
        cnt--; //  node 에서 단어수 하나 감소 
        if (*str == 0)
        {
            is_end = 0; //  끝 부분를 0 로하여 단어가 없음을 표시한다. 
            return;
        }
        rint idx = *str - 'a';
        if (ch[idx] == 0) return;  // 이런 경우는 없다.  있는 단어만 들어온다. 
        ch[idx]->erase(str + 1);// 다음 문자 확인 
    }
    //
    //   word 가 전체 Trie 상  몇번째로 insert 되어 있는지 확인한다. 
    //
    int get_index(char *str, int index = 1) // 1부터 시작
    {
        if (*str == 0)
        {
            return index;
        }
        if (is_end)++index; // 현재 단어가 존재한는 경우  index 증가 
        rint idx = *str - 'a';
        for (rint i = 0; i < idx; ++i)
        {
            if (ch[i] != 0) index += ch[i]->cnt; //동일 level 앞쪽에 단어수를 더한다. 
        }
        return ch[idx]->get_index(str + 1, index); // 다음 아래 노드로 이동 한다. 
    }
};
 
Trie pool[400000]; // memory pool  40000* MAX_L 이상이면 된다 넉넉하게 
int p_idx;
//
//   memory new /allocation 대비 
//
Trie * get_node()
{
    Trie *p = &pool[p_idx++];
    for (rint i = 0; i < 26; ++i)p->ch[i] = 0;
    p->cnt = p->is_end = 0;
    return p;
}
 
Trie *root; // root node
 
void init(int N, char mWordList[][MAX_L + 1])
{
    p_idx = 0;
    root =get_node();// root 노드 만들기 
    for (rint i = 0; i < N; ++i)
    {
        root->add(mWordList[i]);
    }
}
 
int add(char mWord[])
{
    if (root->find(mWord)) return 0;// 이미 있는지 확인 
    root->add(mWord);
    return 1;
}
 
int erase(char mWord[])
{
    if (!root->find(mWord)) return 0; // 존재하는지 확인 
    root->erase(mWord);
    return 1;
}
 
RESULT find(char mInitial, int mIndex)
{
    RESULT res = { 0 };
    if (root->cnt < mIndex) return res; // 전체 word 수 보다  크다면
    rint idx = mInitial - 'a';
    // 주어진 첫글자의 노드가 있는지 있다면  현재 Trie상 있는 단어의 갯수확인
    if (root->ch[idx] == 0 || root->ch[idx]->cnt < mIndex) return res; 
    //아래는  반드시 단어 존재 
    register Trie *cur = root->ch[idx]; // 첫글자 노드로 이동 
    rint p = 0;
    while (mIndex)
    {
        res.word[p++] = idx + 'a';  // Tree 를 내려가면서 해당 단어를 차례로 add 한다. 
        if (mIndex == 1 && cur->is_end) {  //찾았다. -->현재 남은 단어수가 1이고 현재가 단어 끝인경우 
            break;
        }
        if (cur->is_end) mIndex--; // 현재 단어의 끝인경우 단어 index 에서 하나 뺀다. 
        // 동일 level 의 node 의 단어수가 현재 남은 단어수(mIndex) 보다 작은 경우 뺀다. 
        // 큰경우 그 노드 아래쪽에 원하는 단어가 있다. 
        for (idx = 0; idx < 26; ++idx)
        {
            if (cur->ch[idx] != 0 && cur->ch[idx]->cnt >= mIndex) break;
            if (cur->ch[idx] != 0) mIndex -= cur->ch[idx]->cnt;
        }
        cur = cur->ch[idx]; // 아래쪽으로  현재 노드를 이동한다. 
    }
    res.success = 1;
    res.word[p] = '\0';
    return res;
}
 
int getIndex(char mWord[])
{
    if (!root->find(mWord)) return 0; // 찾고자하는 단어가 있는지 확인 
    return root->get_index(mWord); //있다면 몇번째 단어 인지 확인 
}

static char mWordList[MAX_N][MAX_L + 1];

static bool run()
{
	int Q, N, mIndex;

	int ret = -1, ans;

	RESULT res;

	char mWord[MAX_L + 1];

	scanf("%d", &Q);

	bool okay = false;

	for (int q = 0; q < Q; ++q)
	{
		int cmd;
		scanf("%d", &cmd);
		switch(cmd)
		{
		case CMD_INIT:
			scanf("%d", &N);
			for (int i = 0; i < N; ++i)
				scanf("%s", mWordList[i]);
			init(N, mWordList);
			okay = true;
			break;
		case CMD_ADD:
			scanf("%s", mWord);
			ret = add(mWord);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_ERASE:
			scanf("%s", mWord);
			ret = erase(mWord);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_FIND:
			scanf("%s %d", mWord, &mIndex);
			res = find(mWord[0], mIndex);
			scanf("%d", &ans);
			if (res.success != ans)
				okay = false;
			if (ans)
			{
				scanf("%s", mWord);
				if (strcmp(res.word, mWord) != 0)
					okay = false;
			}
			break;
		case CMD_GET_INDEX:
			scanf("%s", mWord);
			ret = getIndex(mWord);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		default:
			okay = false;
			break;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int TC, MARK;

	scanf("%d %d", &TC, &MARK);
	for (int tc = 1; tc <= TC; ++tc)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}