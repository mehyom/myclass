package edu.sswu.vm;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class StockManager {
	Set<Product> items;
	Map<Integer, Product> itemMap;
	public StockManager() {
		items = Utils.toSet(
				new Product(1,"사이다", 700, 2),
				new Product(2,"콜라", 500, 2),
				new Product(3,"탄산수", 600, 1),
				new Product(4,"녹차", 1000, 1),
				new Product(5,"홍차", 1000, 0)
				);
		itemMap = items.stream().collect(Collectors.toMap(Product::getId, x->x));
	}
	public List<Product> queryItems() {
		List<Product> result = new ArrayList<>(items);
		Collections.sort(result, Comparator.comparing(Product::getId));
		return result;
	}
	public Product queryStock(int selectItem) {
		return itemMap.get(selectItem);
	}
	public void releaseStock(Product selectProduct) {
		itemMap.computeIfPresent(selectProduct.getId(), (id, item) -> {
			item.releaseQty();
			return item;
		});
	}
}
