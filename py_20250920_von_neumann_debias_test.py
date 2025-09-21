import random

def biased_coin(bias=0.7):
    """模拟有偏硬币抛掷
    :param bias: 正面出现的概率 (默认0.7)
    :return: 1(正面) 或 0(反面)
    """
    return 1 if random.random() < bias else 0  # 

def von_neumann_debias(bias=0.7):
    """冯·诺依曼去偏方法
    :param bias: 有偏硬币的偏置概率
    :return: (最终结果, 抛掷过程记录)
    """
    process = []
    while True:
        # 连续抛掷两次
        first = biased_coin(bias)
        second = biased_coin(bias)
        process.append((first, second))
        
        # 结果不同时返回第一次结果（理论证明可消除偏差）
        if first != second:
            return first, process  # 

# 测试示例
if __name__ == "__main__":
    bias = 0.7  # 有偏硬币正面概率（可改为任意0-1的值）
    print(f"使用偏置概率: {bias} 的硬币进行冯·诺依曼实验")
    
    # 单次测试
    result, process = von_neumann_debias(bias)
    print(f"\n单次实验过程:")
    for i, (first, second) in enumerate(process, 1):
        status = "有效" if first != second else "无效（重试）"
        print(f"尝试{i}: 第一次={first}({'正面' if first else '反面'}), "
              f"第二次={second}({'正面' if second else '反面'}) → {status}")
    
    print(f"\n最终公正结果: {'正面' if result else '反面'} ({result})")
    
    # 概率验证（10万次测试）
    print("\n正在进行概率验证（10万次实验）...")
    results = []
    for _ in range(100000):
        result, _ = von_neumann_debias(bias)
        results.append(result)
    
    heads_prob = sum(results) / len(results)
    print(f"公正化后正面概率: {heads_prob:.4f} (理论值: 0.5000)")