; ModuleID = 'C:/Users/Katy/Documents/Transformer/TRT/Opt2/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: argmemonly noinline
define void @apatb_score_matrix_ir([3 x float]* %score_m, [3 x float]* %queries, [3 x float]* %keys_t) local_unnamed_addr #0 {
entry:
  %score_m_copy = alloca [3 x [3 x float]], align 512
  %queries_copy = alloca [3 x [3 x float]], align 512
  %keys_t_copy = alloca [3 x [3 x float]], align 512
  %0 = bitcast [3 x float]* %score_m to [3 x [3 x float]]*
  %1 = bitcast [3 x float]* %queries to [3 x [3 x float]]*
  %2 = bitcast [3 x float]* %keys_t to [3 x [3 x float]]*
  call fastcc void @copy_in([3 x [3 x float]]* %0, [3 x [3 x float]]* nonnull align 512 %score_m_copy, [3 x [3 x float]]* %1, [3 x [3 x float]]* nonnull align 512 %queries_copy, [3 x [3 x float]]* %2, [3 x [3 x float]]* nonnull align 512 %keys_t_copy)
  %3 = getelementptr inbounds [3 x [3 x float]], [3 x [3 x float]]* %score_m_copy, i32 0, i32 0
  %4 = getelementptr inbounds [3 x [3 x float]], [3 x [3 x float]]* %queries_copy, i32 0, i32 0
  %5 = getelementptr inbounds [3 x [3 x float]], [3 x [3 x float]]* %keys_t_copy, i32 0, i32 0
  call void @apatb_score_matrix_hw([3 x float]* %3, [3 x float]* %4, [3 x float]* %5)
  call fastcc void @copy_out([3 x [3 x float]]* %0, [3 x [3 x float]]* nonnull align 512 %score_m_copy, [3 x [3 x float]]* %1, [3 x [3 x float]]* nonnull align 512 %queries_copy, [3 x [3 x float]]* %2, [3 x [3 x float]]* nonnull align 512 %keys_t_copy)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @copy_in([3 x [3 x float]]* readonly, [3 x [3 x float]]* noalias align 512, [3 x [3 x float]]* readonly, [3 x [3 x float]]* noalias align 512, [3 x [3 x float]]* readonly, [3 x [3 x float]]* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0a3a3f32([3 x [3 x float]]* align 512 %1, [3 x [3 x float]]* %0)
  call fastcc void @onebyonecpy_hls.p0a3a3f32([3 x [3 x float]]* align 512 %3, [3 x [3 x float]]* %2)
  call fastcc void @onebyonecpy_hls.p0a3a3f32([3 x [3 x float]]* align 512 %5, [3 x [3 x float]]* %4)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @onebyonecpy_hls.p0a3a3f32([3 x [3 x float]]* noalias align 512, [3 x [3 x float]]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [3 x [3 x float]]* %0, null
  %3 = icmp eq [3 x [3 x float]]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx12 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  br label %for.loop2

for.loop2:                                        ; preds = %for.loop2, %for.loop
  %for.loop.idx311 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %for.loop2 ]
  %dst.addr57.gep9 = getelementptr [3 x [3 x float]], [3 x [3 x float]]* %0, i64 0, i64 %for.loop.idx12, i64 %for.loop.idx311
  %5 = bitcast float* %dst.addr57.gep9 to i8*
  %src.addr68.gep10 = getelementptr [3 x [3 x float]], [3 x [3 x float]]* %1, i64 0, i64 %for.loop.idx12, i64 %for.loop.idx311
  %6 = bitcast float* %src.addr68.gep10 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %6, i64 4, i1 false)
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx311, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 3
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %for.loop2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx12, 1
  %exitcond13 = icmp ne i64 %for.loop.idx.next, 3
  br i1 %exitcond13, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #3

; Function Attrs: argmemonly noinline
define internal fastcc void @copy_out([3 x [3 x float]]*, [3 x [3 x float]]* noalias readonly align 512, [3 x [3 x float]]*, [3 x [3 x float]]* noalias readonly align 512, [3 x [3 x float]]*, [3 x [3 x float]]* noalias readonly align 512) unnamed_addr #4 {
entry:
  call fastcc void @onebyonecpy_hls.p0a3a3f32([3 x [3 x float]]* %0, [3 x [3 x float]]* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0a3a3f32([3 x [3 x float]]* %2, [3 x [3 x float]]* align 512 %3)
  call fastcc void @onebyonecpy_hls.p0a3a3f32([3 x [3 x float]]* %4, [3 x [3 x float]]* align 512 %5)
  ret void
}

declare void @apatb_score_matrix_hw([3 x float]*, [3 x float]*, [3 x float]*)

define void @score_matrix_hw_stub_wrapper([3 x float]*, [3 x float]*, [3 x float]*) #5 {
entry:
  %3 = bitcast [3 x float]* %0 to [3 x [3 x float]]*
  %4 = bitcast [3 x float]* %1 to [3 x [3 x float]]*
  %5 = bitcast [3 x float]* %2 to [3 x [3 x float]]*
  call void @copy_out([3 x [3 x float]]* null, [3 x [3 x float]]* %3, [3 x [3 x float]]* null, [3 x [3 x float]]* %4, [3 x [3 x float]]* null, [3 x [3 x float]]* %5)
  %6 = bitcast [3 x [3 x float]]* %3 to [3 x float]*
  %7 = bitcast [3 x [3 x float]]* %4 to [3 x float]*
  %8 = bitcast [3 x [3 x float]]* %5 to [3 x float]*
  call void @score_matrix_hw_stub([3 x float]* %6, [3 x float]* %7, [3 x float]* %8)
  call void @copy_in([3 x [3 x float]]* null, [3 x [3 x float]]* %3, [3 x [3 x float]]* null, [3 x [3 x float]]* %4, [3 x [3 x float]]* null, [3 x [3 x float]]* %5)
  ret void
}

declare void @score_matrix_hw_stub([3 x float]*, [3 x float]*, [3 x float]*)

attributes #0 = { argmemonly noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly nounwind }
attributes #4 = { argmemonly noinline "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
