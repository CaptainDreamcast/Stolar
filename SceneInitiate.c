void SceneInitiate(uint32 StreamingLoadTime, uint32 List){
StreamingLoad(StreamingLoadTime);
pvr_scene_begin();
pvr_list_begin(List);
}