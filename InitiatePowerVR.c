void InitiatePowerVR(){

pvr_init_params_t RenderingStuff;

RenderingStuff.opb_sizes[0] = 16;
RenderingStuff.opb_sizes[1] = 0;
RenderingStuff.opb_sizes[2] = 16;
RenderingStuff.opb_sizes[3] = 0;
RenderingStuff.opb_sizes[4] = 16;

RenderingStuff.vertex_buf_size = 512*1024;

RenderingStuff.dma_enabled = 0;

RenderingStuff.fsaa_enabled = 0;

pvr_init(&RenderingStuff);

}