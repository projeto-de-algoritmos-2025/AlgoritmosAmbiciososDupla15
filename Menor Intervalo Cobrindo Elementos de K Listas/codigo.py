import heapq

class Solution:
    def smallestRange(self, nums: list[list[int]]) -> list[int]:
        k = len(nums)
        
        # (valor, indice_da_lista, indice_do_elemento_na_lista)
        min_heap = []
        
        # rastreia o valor máximo na nossa "janela" atual
        current_max = -float('inf')
        
        # 1. Inicializa com o primeiro elemento de cada lista
        for list_index in range(k):
            first_val = nums[list_index][0]
            
            # Adiciona o elemento à heap
            heapq.heappush(min_heap, (first_val, list_index, 0))
            
            # Atualiza o máximo inicial
            current_max = max(current_max, first_val)
            
        # 2. Inicializar o nosso melhor intervalo encontrado
        # O primeiro intervalo é [min_da_heap, current_max]
        min_val, _, _ = min_heap[0]
        
        best_range_start = min_val
        best_range_diff = current_max - min_val

        # 3. Loop para encontrar o menor intervalo
        while True:
            # Extrai o menor elemento da janela atual
            min_val, list_idx, elem_idx = heapq.heappop(min_heap)
            
            # Compara o intervalo atual [min_val, current_max] com o melhor
            current_diff = current_max - min_val
            
            if current_diff < best_range_diff:
                best_range_diff = current_diff
                best_range_start = min_val
            elif current_diff == best_range_diff and min_val < best_range_start:
                # Critério de desempate: se os intervalos têm o mesmo
                # tamanho, prefere o que começa com o menor número
                best_range_start = min_val
                
            # 4. Avança o ponteiro da lista do elemento mínimo
            next_elem_idx = elem_idx + 1
            
            # 5. Condição de Parada: Se alcançamos o fim de uma das listas
            if next_elem_idx == len(nums[list_idx]):
                break
                
            # 6. Adiciona o novo elemento da lista que avançamos
            new_val = nums[list_idx][next_elem_idx]
            heapq.heappush(min_heap, (new_val, list_idx, next_elem_idx))
            
            # Atualiza o máximo da janela
            current_max = max(current_max, new_val)
            
        return [best_range_start, best_range_start + best_range_diff]