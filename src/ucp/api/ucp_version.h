/*
* Copyright (c) NVIDIA CORPORATION & AFFILIATES, 2001-2015. ALL RIGHTS RESERVED.
* See file LICENSE for terms.
*/


/**
 * Construct a UCP version identifier from major and minor version numbers.
 */
#define UCP_VERSION(_major, _minor) \
	(((_major) << UCP_VERSION_MAJOR_SHIFT) | \
	 ((_minor) << UCP_VERSION_MINOR_SHIFT))
#define UCP_VERSION_MAJOR_SHIFT    24
#define UCP_VERSION_MINOR_SHIFT    16


/**
 * UCP API version is 1.15
 */
#define UCP_API_MAJOR    1
#define UCP_API_MINOR    15
#define UCP_API_VERSION  UCP_VERSION(1, 15)
