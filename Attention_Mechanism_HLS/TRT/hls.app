<project xmlns="com.autoesl.autopilot.project" name="TRT" top="score_matrix">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../../tb_transformer.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="transformer.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="transformer.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="Optimization" status="inactive"/>
        <solution name="Not_Opt" status="inactive"/>
        <solution name="Opt2" status="active"/>
    </solutions>
</project>

