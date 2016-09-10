
ListStruct* ListGetWorkingList(ListStruct* ListData, uint8 Position){
uint8 CurrentPosition;

for(CurrentPosition = 0; CurrentPosition < Position; CurrentPosition++) ListData = ListData->Next;

return(ListData);
}

void* ListGet(ListStruct* ListData, uint8 Position){

ListData = ListGetWorkingList(ListData, Position);

return(ListData->Element);
}

ListStruct* ListCreate(){
return(NULL);
}

ListStruct* ListCreateElement(void* Element, ListStruct* Previous, ListStruct* Next){
ListStruct* NewList;

NewList = (ListStruct*)malloc(sizeof(ListStruct));
NewList->Element = Element;
NewList->Previous = Previous;
NewList->Next = Next;

return(NewList);
}

void ListAdd(ListStruct** ListData, void* Element){

ListStruct* CurrentList;

if((*ListData) == NULL) (*ListData) = ListCreateElement(Element, NULL, NULL);
else{
CurrentList = (*ListData);

while(CurrentList->Next != NULL) CurrentList = CurrentList->Next;
CurrentList->Next = ListCreateElement(Element, CurrentList, NULL);
}
}

uint8 ListIncludes(ListStruct* ListData, void* SearchElement){
uint8 ReturnValue;

ReturnValue = 0;
while(ListData != NULL){
if(ListData->Element == SearchElement){
ReturnValue = 1;
ListData = NULL;
}
else ListData = ListData->Next;

}

return(ReturnValue);
}


void ListDestroyAndDeLoad(ListStruct** ListData){

ListStruct* CurrentList;
ListStruct* DeleteList;

CurrentList = (*ListData);
while(CurrentList != NULL){
free(CurrentList->Element);
DeleteList = CurrentList;
CurrentList = CurrentList->Next;
free(DeleteList);
}

(*ListData) = NULL;
}

uint8 ListEmpty(ListStruct* ListData){
uint8 ReturnValue;

if(ListData == NULL) ReturnValue = LogicActive;
else ReturnValue = LogicActiveNot;

return(ReturnValue);
}
