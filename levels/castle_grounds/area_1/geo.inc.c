#include "src/game/envfx_snow.h"

const GeoLayout castle_grounds_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -105, 1, castle_grounds_dl_1_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, 0, -105, 1, castle_grounds_dl_10_mesh_layer_2),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -105, 1, castle_grounds_dl_2_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, -105, 1, castle_grounds_dl_4_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 0, -105, 1, castle_grounds_dl_5_mesh_layer_6),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, -105, 1, castle_grounds_dl_6_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -105, 1, castle_grounds_dl_9_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 28, -2, -37),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 28, -2, -37),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 28, -2, -37),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 28, -2, -37),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, -183, 0, castle_grounds_dl_Water_Box_Mesh_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, -183, 0, castle_grounds_dl_Water_Box_Mesh_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_grounds_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_FREE_ROAM, 0, 102, 0, 0, 2, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, castle_grounds_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
