acmer/
├── .vscode/                 # 编译器与调试配置 (tasks.json, launch.json)
├── templates/               # 竞赛核心算法模板库 (按模块归类)
│   ├── data_structures/     # 线段树、并查集、Fenwick、平衡树
│   ├── graph/               # 最短路、网络流、Tarjan、树剖
│   ├── math/                # 数论、组合数学、线性基
│   └── string/              # KMP、AC自动机、SA
│
├── platforms/               # 【题库轨】：按 OJ 平台扁平存放散题
│   ├── luogu/
│   │   ├── P1000.cpp
│   │   ├── P2986_树形DP.cpp  # 格式：题号[_简记/核心算法标签].cpp
│   │   └── P3372_线段树1.cpp
│   ├── acwing/
│   │   ├── 849_Dijkstra求最短路.cpp
│   │   └── 895_最长上升子序列.cpp
│   ├── leetcode/
│   │   └── 0001_两数之和.cpp
│   ├── matiji/              # 码蹄集
│   └── hdoj/
│
├── contests/                # 【比赛轨】：按比赛体系与场次独立归类
│   ├── codeforces/
│   │   ├── 2026_div2_988/   # 每场比赛一个文件夹
│   │   │   ├── A.cpp
│   │   │   ├── B.cpp
│   │   │   └── C.cpp
│   │   └── 2026_div3_990/
│   ├── atcoder/
│   │   └── abc350/
│   │       ├── A.cpp
│   │       └── B.cpp
│   ├── lanqiao/             # 蓝桥杯省赛/国赛真题
│   └── mock_contests/       # 组队模拟赛、省赛选拔、牛客暑期多校
│       └── 2026_sccpc_warmup/
│
└── notes/                   # 知识体系、大纲与复盘 Markdown
    ├── roadmaps/            # 训练大纲
    └── contest_retro/       # 比赛复盘与反思
