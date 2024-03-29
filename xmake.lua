add_rules("mode.debug", "mode.release", {debuginfo = 'all'})

target("fog")
    add_defines("XMAKE")
    set_kind("binary")
    set_languages("cxx23")
    add_links("protobuf")
    add_includedirs("src")
    add_includedirs("src/proto")
    add_includedirs("src/public")
    add_files("src/**.cc")
    -- set_policy("build.c++.modules", true)
target_end()


--[[

安装:
sudo add-apt-repository ppa:xmake-io/xmake
sudo apt update
sudo apt install xmake

创建项目: xmake create proj_name
add_requires("opencv") -- 包依赖描述, 类似python的pip, 但是xmake-repo比较小众收录的包少, 如果系统已经安装对应库, add_requires会自动找到
add_packages: 当编译目标存在时, 如果pkg存在, 那么其定义,头文件路径,链接库路径将被自动导入并链接, 等价于add_link,add_include_dir相关路径

]]