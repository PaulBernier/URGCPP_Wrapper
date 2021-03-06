/*
* Copyright (c) 2014, Georgia Tech Research Corporation
* All rights reserved.
*
* Author: Paul Bernier <bernier.pja@gmail.com>
* Date: Jan 2014
*
* Humanoid Robotics Lab Georgia Institute of Technology
* Director: Mike Stilman http://www.golems.org
*
*
* This file is provided under the following "BSD-style" License:
* Redistribution and use in source and binary forms, with or
* without modification, are permitted provided that the following
* conditions are met:
*
* * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above
* copyright notice, this list of conditions and the following
* disclaimer in the documentation and/or other materials provided
* with the distribution.
*
* * Neither the name of the Humanoid Robotics Lab nor the names of
* its contributors may be used to endorse or promote products
* derived from this software without specific prior written
* permission
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
* USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef SCANNER3D_H
#define SCANNER3D_H

#include "dxl.h"
#include "urgcppwrapper.h"
#include <osg/Geode>
#include <vector>
#include "scanresultstruct.h"
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

class Scanner3d
{
public:
    Scanner3d(URGCPPWrapper *urg, Dxl *dxl,
              int start_angle_degree = 220, int end_angle_degree = 110, double scan_step_degree = 1);
    void scan();
    void getScan3dGeode(osg::ref_ptr<osg::Geode> geode);

    void getPointCloud(pcl::PointCloud<pcl::PointXYZ> &cloud, bool organized = false);
    void savePointCloudToPCD(const std::string& filename, bool organized = false, bool binary = true);

    void setScanParameters(int start_angle_degree, int end_angle_degree, double scan_step_degree);

private:
    URGCPPWrapper* urg;
    Dxl* dxl;

    RawScan3dResult raw_scan3d_result;

    // Params
    int start_angle_degree;
    int end_angle_degree;
    double scan_step_degree;

    void updateScanParam();
    void moveHeadToInitialPosition();
};

#endif // SCANNER3D_H
