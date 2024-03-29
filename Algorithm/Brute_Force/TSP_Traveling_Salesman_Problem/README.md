###Prob : Traveling Salesman Problem
- #### 문제
  ##### 모든 노드가 연결되어 있고, 노드간의 거리가 주어졌을 때, 모든 노드를 방문하는 최소 길이를 찾는다.
  
- #### 풀이 : 완전탐색 + Dynamic Programming
  ##### 완전탐색으로 풀이할 경우 경우의 수는 노드 개수의 조합 => 시간복잡도가 엄청나게 크다
  ##### 그래서 DP로 풀이
- #### 비트연산
  ##### 방문했던 노드를 체크하는 방식을 Boolean array를 사용하지 않고, 비트 연산을 사용
  ##### 비트 연산을 사용하는 것이, DP 배열의 인덱스로 활용하기 편하기 때문
