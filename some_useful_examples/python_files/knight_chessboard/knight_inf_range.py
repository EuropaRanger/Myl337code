import numpy as np
import matplotlib.pyplot as plt
from collections import deque
from matplotlib.collections import LineCollection

# ---------- 参数 ----------
START = (0, 0)          # 起点
MAX_STEPS = 18          # BFS 最大步数（层数）
SHOW_PATH = True        # 是否画出 BFS 树边
SHOW_STEP_NUM = True    # 是否在格子上标注步数
FIGSIZE = (12, 12)

# 骑士的 8 种走法
MOVES = [(2, 1), (1, 2), (-1, 2), (-2, 1),
         (-2, -1), (-1, -2), (1, -2), (2, -1)]

# ---------- BFS ----------
def knight_bfs(start, max_steps):
    """从 start 出发做 BFS，返回:
       dist: dict[(x,y)] = 步数
       parent: dict[(x,y)] = 前驱格子
    """
    dist = {start: 0}
    parent = {start: None}
    q = deque([start])

    while q:
        x, y = q.popleft()
        d = dist[(x, y)]
        if d >= max_steps:
            continue
        for dx, dy in MOVES:
            nx, ny = x + dx, y + dy
            if (nx, ny) not in dist:
                dist[(nx, ny)] = d + 1
                parent[(nx, ny)] = (x, y)
                q.append((nx, ny))
    return dist, parent

dist, parent = knight_bfs(START, MAX_STEPS)

# ---------- 准备绘图数据 ----------
coords = np.array(list(dist.keys()))        # (N,2)
steps = np.array([dist[c] for c in dist])   # (N,)

# 边界（用于设置坐标轴范围）
xmin, xmax = coords[:, 0].min() - 1, coords[:, 0].max() + 1
ymin, ymax = coords[:, 1].min() - 1, coords[:, 1].max() + 1

fig, ax = plt.subplots(figsize=FIGSIZE)

# 1) 画棋盘格（浅色交错，仅用于视觉参考）
xs = np.arange(xmin, xmax + 1)
ys = np.arange(ymin, ymax + 1)
X, Y = np.meshgrid(xs, ys)
parity = (X + Y) % 2
ax.imshow(parity, extent=[xmin - 0.5, xmax + 0.5, ymin - 0.5, ymax + 0.5],
          cmap='Greys', alpha=0.25, origin='lower', zorder=0)

# 2) 画 BFS 树的边
if SHOW_PATH:
    segments = []
    for node, par in parent.items():
        if par is not None:
            segments.append([par, node])
    lc = LineCollection(segments, colors='tab:blue', linewidths=0.6,
                        alpha=0.6, zorder=1)
    ax.add_collection(lc)

# 3) 画格子点，颜色按步数深浅
sc = ax.scatter(coords[:, 0], coords[:, 1], c=steps, cmap='turbo',
                s=40, edgecolors='k', linewidths=0.4, zorder=2)
cbar = fig.colorbar(sc, ax=ax, shrink=0.8)
cbar.set_label('BFS (distance)')

# 4) 可选：在每个格子上标注步数
if SHOW_STEP_NUM:
    for (x, y), d in dist.items():
        ax.text(x, y, str(d), ha='center', va='center',
                fontsize=6, color='white', zorder=3)

# 5) 标记起点
ax.scatter([START[0]], [START[1]], marker='*', s=300, c='red',
           edgecolors='k', zorder=4, label='start')
ax.legend(loc='upper right')

ax.set_title(f'Knight BFS from {START}, max steps = {MAX_STEPS}\n'
             f'visited cells = {len(dist)}')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_aspect('equal')
ax.set_xlim(xmin - 0.5, xmax + 0.5)
ax.set_ylim(ymin - 0.5, ymax + 0.5)
ax.grid(True, linestyle=':', alpha=0.4)

plt.tight_layout()
plt.show()