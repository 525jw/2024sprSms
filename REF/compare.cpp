struct cmp{
   bool operator()(자료형 a,자료형 b)
   {
      return a>b;//최소힙
   }
}
priority_queue<자료형, vector<자료형>, cmp> pq;



bool cmp(자료형 a,자료형 b)
{
   return a<b;//오름차순 정렬
}
sort(시작주소, 끝주소, cmp)
//sort(arr,arr+n,cmp)