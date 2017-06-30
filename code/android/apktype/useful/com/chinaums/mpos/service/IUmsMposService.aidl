package com.chinaums.mpos.service;

import android.os.Bundle;
import com.chinaums.mpos.service.IUmsMposResultListener;

interface IUmsMposService {
	void setDevice(in Bundle args, in IUmsMposResultListener listener);
	void bookOrder(in Bundle args, in IUmsMposResultListener listener);
	void payOrder(in Bundle args, in IUmsMposResultListener listener);
	void showTransactionInfoAndSign(in Bundle args, in IUmsMposResultListener listener);
	void queryOrderInfo(in Bundle args, in IUmsMposResultListener listener);
	void cancelTransaction(in Bundle args, in IUmsMposResultListener listener);
	void returnGoods(in Bundle args, in IUmsMposResultListener listener);
	void printBill(in Bundle args, in IUmsMposResultListener listener);
	void checkVersionUpdate(in Bundle args, in IUmsMposResultListener listener);
	void getDeviceId(in Bundle args, in IUmsMposResultListener listener);
	void pay(in Bundle args, in IUmsMposResultListener listener);
	void preAuth(in Bundle args, in IUmsMposResultListener listener);
	void preAuthFin(in Bundle args, in IUmsMposResultListener listener);
	void preAuthCancel(in Bundle args, in IUmsMposResultListener listener);
	void preAuthFinCancel(in Bundle args, in IUmsMposResultListener listener);
	void checkCurrentEnv(in Bundle args, in IUmsMposResultListener listener);
	void getCardNum(in Bundle args, in IUmsMposResultListener listener);
	void refund(in Bundle args, in IUmsMposResultListener listener);
	int umspay(in Bundle args, in IUmsMposResultListener listener);
}

