# Linux关机与重启命令详解

## 一、shutdown - 最安全的关机命令(推荐)

`shutdown` 是最安全、最常用的关机命令,可以定时关机、发送警告消息给所有登录用户。

### 基本语法
```bash
shutdown [选项] [时间] [警告消息]
```

### 常用参数

| 参数 | 说明 |
|------|------|
| `-h` | 关机(halt),等同于 `shutdown -P now` |
| `-r` | 重启(reboot) |
| `-c` | 取消正在进行的关机操作 |
| `-k` | 只发送警告消息,不真正关机 |
| `-P` | 关闭电源(power off) |
| `-H` | 停止系统运行但不关闭电源(halt) |
| `-f` | 快速关机,不进行文件系统检查 |
| `-F` | 强制在下次启动时进行文件系统检查 |
| `-n` | 不调用init程序直接关机(不推荐) |
| `-t 秒数` | 指定延迟时间 |

### 时间格式
- `now` - 立即执行
- `+m` - m分钟后执行
- `HH:MM` - 指定具体时间(24小时制)

### 使用示例

```bash
# 立即关机
shutdown -h now
shutdown -P now

# 5分钟后关机,并发送警告消息
shutdown -h +5 "系统将在5分钟后关机维护"

# 晚上10点关机
shutdown -h 22:00

# 立即重启
shutdown -r now

# 10分钟后重启
shutdown -r +10 "系统将在10分钟后重启"

# 取消已计划的关机
shutdown -c

# 只发送警告消息,不真正关机
shutdown -k +10 "提醒:系统将在10分钟后维护"
```

---

## 二、halt - 停止系统运行

`halt` 用于停止CPU运行,关闭系统内核,但可能不会切断电源。

### 常用参数

| 参数 | 说明 |
|------|------|
| `-p` | 关闭电源(等同于poweroff) |
| `-f` | 强制关机,不调用shutdown |
| `-w` | 不真正关机,只在/var/log/wtmp中写入记录 |
| `-d` | 不在wtmp中写入记录 |
| `-i` | 关机前关闭所有网络接口 |

### 使用示例

```bash
# 停止系统(可能不断电)
halt

# 停止系统并关闭电源
halt -p

# 强制关机
halt -f
```

---

## 三、poweroff - 关闭电源

`poweroff` 用于完全关闭系统并切断电源,是实际中最常用的关机命令之一。

### 常用参数

| 参数 | 说明 |
|------|------|
| `-f` | 强制关机,不调用shutdown |
| `-w` | 不真正关机,只写记录到wtmp |
| `-d` | 不在wtmp中写入记录 |
| `-i` | 关机前关闭网络接口 |
| `-h` | 显示帮助信息 |

### 使用示例

```bash
# 立即关机并断电
poweroff

# 强制关机
poweroff -f
```

**注意**: `poweroff` 实际上是指向 `systemctl poweroff` 的符号链接(在使用systemd的系统上)。

---

## 四、reboot - 重启系统

`reboot` 用于重新启动计算机系统。

### 常用参数

| 参数 | 说明 |
|------|------|
| `-f` | 强制重启,不调用shutdown |
| `-w` | 不真正重启,只写记录到wtmp |
| `-d` | 不在wtmp中写入记录 |
| `-i` | 重启前关闭网络接口 |
| `-p` | 重启前先关闭电源(某些系统支持) |

### 使用示例

```bash
# 正常重启
reboot

# 强制重启
reboot -f

# 等同于 shutdown -r now
reboot
```

**注意**: 在现代Linux系统中,`reboot` 通常是指向 `systemctl reboot` 的符号链接。

---

## 五、systemctl - systemd系统的现代方式

在使用systemd的现代Linux发行版(如CentOS 7+, Ubuntu 16.04+, Debian 8+)中,推荐使用 `systemctl` 命令。

### 关机相关命令

```bash
# 关机并断电
systemctl poweroff

# 重启系统
systemctl reboot

# 挂起系统(睡眠)
systemctl suspend

# 休眠系统
systemctl hibernate

# 混合休眠(挂起到磁盘)
systemctl hybrid-sleep
```

### 优势
- 更现代化的管理方式
- 更好的服务依赖管理
- 统一的系统管理接口

---

## 六、各命令对比总结

| 命令 | 是否断电 | 安全性 | 推荐场景 |
|------|---------|--------|---------|
| `shutdown -h now` | ✓ | ★★★★★ | **生产环境首选**,可通知用户 |
| `shutdown -r now` | - | ★★★★★ | **生产环境重启首选** |
| `poweroff` | ✓ | ★★★★☆ | 日常使用,简单直接 |
| `halt -p` | ✓ | ★★★★☆ | 需要停止系统时 |
| `halt` | ✗ | ★★★☆☆ | 只需停止CPU,不断电 |
| `reboot` | - | ★★★★☆ | 日常重启 |
| `systemctl poweroff` | ✓ | ★★★★★ | systemd系统推荐 |
| `systemctl reboot` | - | ★★★★★ | systemd系统推荐 |

---

## 七、注意事项与最佳实践

### 1. 权限要求
- 普通用户需要使用 `sudo` 执行关机/重启命令
- root用户可以直接执行

```bash
# 普通用户
sudo shutdown -h now
sudo reboot

# root用户
shutdown -h now
reboot
```

### 2. 生产环境建议
- ✅ **始终使用 `shutdown` 命令**,因为它会:
  - 通知所有登录用户
  - 优雅地停止服务
  - 同步文件系统
  - 卸载文件系统
  
- ❌ **避免在生产环境使用 `-f` 强制参数**,可能导致:
  - 数据丢失
  - 文件系统损坏
  - 服务异常终止

### 3. 远程服务器管理
```bash
# 通过SSH远程关机(谨慎使用!)
ssh user@remote_host "sudo shutdown -h +5 '维护关机'"

# 确保有带外管理(iDRAC/iLO/IPMI)以防万一
```

### 4. 查看关机日志
```bash
# 查看最近的关机/重启记录
last -x | grep -E "shutdown|reboot"

# 查看系统日志
journalctl -b -1 -e  # 查看上一次启动的日志末尾
```

### 5. 定时任务关机
```bash
# 使用at命令安排关机
echo "shutdown -h now" | at 23:00

# 使用cron定时关机(每天凌晨2点)
crontab -e
# 添加: 0 2 * * * /sbin/shutdown -h now
```

---

## 八、常见问题

### Q1: 如何取消已计划的关机?
```bash
shutdown -c
```

### Q2: 关机和重启有什么区别?
- **关机**: 停止系统运行,切断电源
- **重启**: 停止系统后立即重新启动

### Q3: 哪个命令最快?
`halt -f` 或 `poweroff -f` 最快,但**不安全**,不推荐使用。

### Q4: 如何在图形界面关机?
大多数桌面环境提供图形化的关机按钮,底层也是调用上述命令。

### Q5: 紧急情况下如何强制关机/重启?

当系统完全无响应,常规命令无法执行时,可以使用以下方法:

#### 方法1: 通过 SysRq 接口(内核级别)

```bash
# 立即重启(不推荐,可能导致数据丢失)
echo b | sudo tee /proc/sysrq-trigger

# 立即关机(不推荐,可能导致数据丢失)
echo o | sudo tee /proc/sysrq-trigger
```

**⚠️ 重要警告:**
- 这些命令**不会同步文件系统**,直接触发内核操作
- **必须先执行 sync** 以避免数据丢失:
  ```bash
  # 安全的做法:先同步数据,再重启/关机
  sync
  echo b | sudo tee /proc/sysrq-trigger  # 重启
  
  sync
  echo o | sudo tee /proc/sysrq-trigger  # 关机
  ```
- 仅在系统完全卡死、SSH无响应等极端情况下使用
- 需要内核启用了 SysRq 功能(`kernel.sysrq = 1`)

#### 方法2: REISUB 安全重启序列

通过键盘或命令依次执行,更安全的方式:

```bash
# 通过命令行执行 REISUB 序列
# R - 将键盘从原始模式切换为 XLATE 模式
echo r | sudo tee /proc/sysrq-trigger

# E - 向所有进程发送 SIGTERM 信号(优雅终止)
echo e | sudo tee /proc/sysrq-trigger

# I - 向所有进程发送 SIGKILL 信号(强制终止)
echo i | sudo tee /proc/sysrq-trigger

# S - 同步所有挂载的文件系统
echo s | sudo tee /proc/sysrq-trigger

# U - 以只读方式重新挂载所有文件系统
echo u | sudo tee /proc/sysrq-trigger

# B - 立即重启系统
echo b | sudo tee /proc/sysrq-trigger
```

**记忆口诀**: "**R**eboot **E**ven **I**f **S**ystem **U**tterly **B**roken"  
(即使系统完全崩溃也要重启)

或者反过来记关机序列 **REISO**:
```bash
# R-E-I-S-O (O = power Off)
for key in r e i s o; do echo $key | sudo tee /proc/sysrq-trigger; sleep 1; done
```

#### 方法3: 物理 SysRq 键组合

在物理键盘上按住 `Alt + SysRq`(通常是 PrintScreen 键),然后依次按下:
- **重启**: R → E → I → S → U → B (每个键间隔1-2秒)
- **关机**: R → E → I → S → O

#### 对比总结

| 方法 | 安全性 | 适用场景 | 数据风险 |
|------|--------|---------|---------|
| `shutdown -h now` | ★★★★★ | 正常情况 | 无 |
| `shutdown -h -f now` | ★★★☆☆ | 服务无响应 | 低 |
| `sync + echo b/o` | ★★☆☆☆ | 系统部分卡死 | 中 |
| REISUB 序列 | ★★★★☆ | 系统严重卡死 | 低 |
| 直接 `echo b/o` | ★☆☆☆☆ | 完全无响应(最后手段) | **高** |

**最佳实践**: 
1. 优先尝试常规 `shutdown` 命令
2. 如果无响应,尝试 `sync` 后再用 SysRq
3. REISUB 比直接 reboot/shutdown 更安全
4. 直接 `echo b/o` 是**最后的选择**,仅在所有其他方法都失败时使用

---

## 九、总结

对于不同的使用场景,推荐的命令如下:

- 🏆 **生产环境**: `shutdown -h now` 或 `shutdown -r now`
- 💻 **个人电脑**: `poweroff` 或 `reboot`
- 🔧 **systemd系统**: `systemctl poweroff` 或 `systemctl reboot`
- ⚠️ **紧急情况**: `shutdown -h -f now` (谨慎使用)

记住:**安全第一,数据无价!** 在执行关机或重启操作前,务必确认所有重要工作已保存。
