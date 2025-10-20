```md
# 632. Menor Intervalo Cobrindo Elementos de K Listas
(Smallest Range Covering Elements from K Lists)

Você tem $k$ listas de inteiros ordenadas em ordem não decrescente. Encontre o **menor** intervalo que inclui pelo menos um número de cada uma das $k$ listas.

Nós definimos que o intervalo $[a, b]$ é menor que o intervalo $[c, d]$ se $b - a < d - c$, ou $a < c$ se $b - a == d - c$.

**Exemplo 1:**

```

Entrada: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Saída: [20,24]
Explicação:
Lista 1: [4, 10, 15, 24, 26], 24 está no intervalo [20,24].
Lista 2: [0, 9, 12, 20], 20 está no intervalo [20,24].
Lista 3: [5, 18, 22, 30], 22 está no intervalo [20,24].

```

**Exemplo 2:**

```

Entrada: nums = [[1,2,3],[1,2,3],[1,2,3]]
Saída: [1,1]

```

**Restrições:**

* `nums.length == k`
* $1 \le k \le 3500$
* $1 \le \text{nums[i].length} \le 50$
* $-10^5 \le \text{nums[i][j]} \le 10^5$
* `nums[i]` é ordenada em ordem não decrescente.
```