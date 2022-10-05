package edu.sswu.vm;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Cash {
	protected Map<Integer, Coin> coins;
	protected Map<Integer, List<Bill>> bills;
	public Cash() {
		this.coins = new HashMap<>();
		this.bills = new HashMap<>();
	}

	public int amount() {
		int billAmount = bills.values().stream().mapToInt(v -> v.stream().mapToInt(Money::getFaceValue).sum()).sum();
		int coinAmount = coins.values().stream().mapToInt(coin -> coin.realValue()).sum();
		return billAmount + coinAmount;
	}
	public void moveTo(final Cash target) {
		coins.forEach((key, value) -> target.coins.merge(key, value, (v1, v2) -> { 
			v1.addCount(v2.getCount());
			return v1;}));
		coins.clear();
		bills.forEach((key, value) -> target.bills.merge(key, value, (v1, v2) -> { 
			v1.addAll(v2);
			return v1;}));
		bills.clear();
	}
	public void credits(Money money) {
		if (money instanceof Coin) {
			coins.compute(money.getFaceValue(), (k,v) -> {
				if (v == null) {
					return new Coin(money.getId(), money.getName(), money.getFaceValue(), 1);
				} else {
					((Coin)v).addCount(money.realValue()/money.getFaceValue());
					return v;
				}
			});
		} else {
			bills.compute(money.getFaceValue(), (k,v) -> {
				if (v == null) {
					v = new ArrayList<>();
				}
				v.add(new Bill(money.getId(), money.getName(), money.getFaceValue(), ((Bill)money).getSerialNumber()));
				return v;
			});
		}
	}
	public void debits() {
		coins.clear();
		bills.clear();
	}
}
