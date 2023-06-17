/*
 * VVC reference management
 *
 * Copyright (C) 2023 Nuo Mi
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVCODEC_VVC_REFS_H
#define AVCODEC_VVC_REFS_H

#include "vvcdec.h"

#define INV_POC INT_MIN
#define GDR_IS_RECOVERED(s)  (s->gdr_recovery_point_poc == INV_POC)
#define GDR_SET_RECOVERED(s) (s->gdr_recovery_point_poc =  INV_POC)

int ff_vvc_output_frame(VVCContext *s, VVCFrameContext *fc, AVFrame *out, int no_output_of_prior_pics_flag, int flush);
void ff_vvc_bump_frame(VVCContext *s, VVCFrameContext *fc);
int ff_vvc_set_new_ref(VVCContext *s, VVCFrameContext *fc, AVFrame **frame);
const RefPicList *ff_vvc_get_ref_list(const VVCFrameContext *fc, const VVCFrame *ref, int x0, int y0);
int ff_vvc_frame_rpl(VVCContext *s, VVCFrameContext *fc, const SliceContext *sc);
int ff_vvc_slice_rpl(VVCContext *s, VVCFrameContext *fc, const SliceContext *sc);
void ff_vvc_unref_frame(VVCFrameContext *fc, VVCFrame *frame, int flags);
void ff_vvc_clear_refs(VVCFrameContext *fc);

void ff_vvc_report_progress(VVCFrame *frame, int n);
void ff_vvc_await_progress(VVCFrame *frame, int n);

#endif // AVCODEC_VVC_REFS_H