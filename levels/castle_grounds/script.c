#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_grounds_geo_0006F4), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_VCUTM_GRILL, castle_grounds_geo_00070C), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_FLAG, castle_grounds_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CANNON_GRILL, castle_grounds_geo_000724), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x00, LEVEL_CASTLE, 0x01, 0x00, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_CASTLE, 0x01, 0x01, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_CASTLE, 0x03, 0x02, WARP_NO_CHECKPOINT),
		WARP_NODE(0x03, LEVEL_CASTLE_GROUNDS, 0x01, 0x03, WARP_NO_CHECKPOINT),
		WARP_NODE(0x04, LEVEL_CASTLE_GROUNDS, 0x01, 0x04, WARP_NO_CHECKPOINT),
		WARP_NODE(0x05, LEVEL_VCUTM, 0x01, 0x14, WARP_NO_CHECKPOINT),
		WARP_NODE(0x06, LEVEL_CASTLE_GROUNDS, 0x01, 0x06, WARP_NO_CHECKPOINT),
		WARP_NODE(0x07, LEVEL_CASTLE_GROUNDS, 0x01, 0x07, WARP_NO_CHECKPOINT),
		WARP_NODE(0x08, LEVEL_CASTLE_GROUNDS, 0x01, 0x08, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x14, LEVEL_CASTLE_GROUNDS, 0x01, 0x14, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1E, LEVEL_CASTLE_GROUNDS, 0x01, 0x1E, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x01, 0x03, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 5408, 4398, 3637, 0, -135, 0, 0x0A, bhvAirborneWarp),
		OBJECT(MODEL_NONE, -6901, 2274, -6509, 0, -130, 0, 0x14, bhvAirborneWarp),
		OBJECT(MODEL_NONE, -7430, 1398, -5937, 0, 0, 0, 0, bhvAmbientSounds),
		OBJECT(MODEL_BIRDS, -5069, 748, 3221, 0, 0, 0, 0x01, bhvWaterMist2),
		OBJECT(MODEL_BIRDS, -4711, 640, 433, 0, 0, 0, 0x01, bhvWaterMist2),
		OBJECT(MODEL_BIRDS, 5774, 811, -1114, 0, 0, 0, 0x01, bhvWaterMist2),
		OBJECT(MODEL_NONE, -7430, 1398, 873, 0, 0, 0, 0x00, bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, -80, 1398, 5004, 0, 0, 0, 0x01, bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, 7131, 1398, -2989, 0, 0, 0, 0x02, bhvBirdsSoundLoop),
		OBJECT(MODEL_BUTTERFLY, -4508, 304, 4400, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, 5473, 673, -5322, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -1504, 224, 3196, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -1204, 224, 3296, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -4408, 304, 4500, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -4708, 304, 4100, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -6003, 371, -2621, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -6003, 371, -2321, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, 6543, 359, -617, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, 6143, 359, -617, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, 5773, 673, -5722, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, 5873, 673, -5622, 0, 0, 0, 0, bhvButterfly),
		OBJECT(MODEL_NONE, 0, -102, 0, 0, 0, 0, 0, bhvHiddenAt120Stars),
		OBJECT(MODEL_YELLOW_COIN, -6081, 3425, 2269, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, -6081, 3225, 2269, 0, -29, 0, (3 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1328, 2898, 4484, 0, 90, 0, (3 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 4717, 3053, 3313, 0, 135, 0, (3 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5546, 3280, -3993, 0, 45, 0, (3 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 940, 3468, -9291, 0, 0, 0, (3 << 16), bhvCoinFormation),
		OBJECT(MODEL_YELLOW_COIN, -1328, 3099, 4484, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4717, 3254, 3313, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 5546, 3481, -3993, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 940, 3669, -9291, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, 0, 798, -1710, 0, -180, 0, 0x03, bhvDeathWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_FLAG, -3213, 3246, -3011, 0, 0, 0, 0, bhvCastleFlagWaving),
		OBJECT(MODEL_CASTLE_GROUNDS_FLAG, 3213, 3246, -3011, 0, 0, 0, 0, bhvCastleFlagWaving),
		OBJECT(MODEL_CASTLE_GROUNDS_FLAG, -3835, 3246, -6647, 0, 0, 0, 0, bhvCastleFlagWaving),
		OBJECT(MODEL_CASTLE_GROUNDS_FLAG, 3835, 3246, -6647, 0, 0, 0, 0, bhvCastleFlagWaving),
		OBJECT(MODEL_NONE, 5223, -1077, 1667, 0, 0, 0, 0x08, bhvWaterMist2),
		OBJECT(MODEL_NONE, 4, 2952, -7045, 0, 0, 0, 0x00000000, bhvHiddenStar),
		OBJECT(MODEL_NONE, 0, -102, 0, 0, 0, 0, 0, bhvInvisibleObjectsUnderBridge),
		OBJECT(MODEL_NONE, -3379, -602, -2025, 0, -180, 0, 0x06, bhvLaunchDeathWarp),
		OBJECT(MODEL_NONE, -3379, -602, -2025, 0, -180, 0, 0x08, bhvLaunchStarCollectWarp),
		MARIO_POS(0x01, 0, -1328, 158, 4664),
		OBJECT(MODEL_MIST, -4878, -889, -5690, 0, 0, 0, 0, bhvWaterMist2),
		OBJECT(MODEL_MIST, -4996, -889, -5548, 0, 0, 0, 0x01, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5114, -889, -5406, 0, 0, 0, 0x02, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5212, -889, -5219, 0, 0, 0, 0x03, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5311, -889, -5033, 0, 0, 0, 0x04, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5419, -889, -4895, 0, 0, 0, 0x05, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5527, -889, -4757, 0, 0, 0, 0x06, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5686, -889, -4733, 0, 0, 0, 0x07, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5845, -889, -4710, 0, 0, 0, 0x08, bhvWaterMist2),
		OBJECT(MODEL_CASTLE_GROUNDS_VCUTM_GRILL, 0, -102, 0, 0, 0, 0, 0, bhvMoatGrills),
		OBJECT(MODEL_NONE, -6081, 3425, 2269, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -1328, 3099, 4484, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 4717, 3254, 3313, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 5546, 3481, -3993, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 940, 3669, -9291, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -3799, -1301, -5816, 0, 0, 0, 0x07, bhvSwimmingWarp),
		OBJECT(MODEL_NONE, 4997, -1352, 2258, 0, -150, 0, 0x1E, bhvSwimmingWarp),
		OBJECT(MODEL_NONE, -3379, -917, -2025, 0, 0, 0, 0x00006005, bhvWarp),
		OBJECT(MODEL_NONE, -1328, 158, 4664, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -5812, -2, -5937, 0, 0, 0, 0, bhvWaterfallSoundLoop),
		OBJECT(MODEL_YOSHI, 0, 3072, -5625, 0, 0, 0, 0, bhvYoshi),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SOUND_PLAYER),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -1328, 158, 4664),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};