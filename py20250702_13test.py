import random
from collections import defaultdict

# 常量设置
NUM_SIMULATIONS = 100000
DECKS = 3  # 三副牌
CARDS_PER_DECK = 52
RANKS = [str(n) for n in range(2, 11)] + list("JQKA")
RANK_COUNT = 13  # 每副牌13种点数


def create_deck():
    """创建3副牌的列表，每张牌只标记点数"""
    deck = []
    for _ in range(DECKS):
        for rank in RANKS:
            deck.extend([rank] * 4)  # 每副牌每种点数4张
    return deck


def simulate_once():
    deck = create_deck()
    random.shuffle(deck)
    count = []
    for card in deck:
        if card in count:
            return count, len(count)
        count.append(card)


def main():
    total_drawn = 0
    mm = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for _ in range(NUM_SIMULATIONS):
        cards, length = simulate_once()
        mm[length] = mm[length] + 1
        total_drawn += length
    avg_drawn = total_drawn / NUM_SIMULATIONS
    print(f"模拟 {NUM_SIMULATIONS} 次后的平均亮牌数: {avg_drawn:.2f}")
    sum_ = 0
    for i in range(len(mm)):
        sum_ += mm[i]
        print(
            f"{i} 张牌被亮出的概率: {mm[i] / NUM_SIMULATIONS:.2%}\t 总概率: {sum_ / NUM_SIMULATIONS:.2%}"
        )


if __name__ == "__main__":
    main()
