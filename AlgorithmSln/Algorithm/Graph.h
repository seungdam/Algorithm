#pragma once

struct Vertex
{
	int32 v;
};

// Graph Sample
// 
//     �� �� 2
// 0 �� 1  
//     �� �� 3 �� 4 �� 5

void CreateSimpleGraph();
void CreateGraphAdjacentList();
void CreateGraphAdjacentMatrix();
void CreateWeightGraphAdjacentMatrix();