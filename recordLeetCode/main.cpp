#include<iostream>
//package
#include<algorithm>
//data struct
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<tuple>

using namespace std;


class unionfind {
public:
	vector<int> record;
	vector<int> size;
	int area;
	unionfind(int len) {
		area = len;
		for (int i = 0; i < len; i++) {
			record.push_back(i);
			size.push_back(1);
		}
	}
	int find(int x) {
		if (x == record[x])
			return x;
		return find(record[x]);
	}
	bool un_ion(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (size[x] < size[y]) {
			swap(x, y);
		}
		area--;
		size[x] = size[x] + size[y];
		record[y] = x;
		return true;
	}
	bool connect(int x, int y) {
		x = find(x);
		y = find(y);
		return x == y;
	}
};




namespace lt1631 {
	//vector<int> arr;
	//vector<int> size;
	//int find(int x) {
	//	if (arr[x] == x)
	//		return x;
	//	return find(arr[x]);
	//}
	//bool unionx(int x, int y) {
	//	x = find(x);
	//	y = find(y);
	//	if (x == y) {
	//		return false;
	//	}
	//	if (size[x] < size[y])
	//		swap(x, y);

	//	arr[y] = x;
	//	size[x] += size[y];
	//	return true;
	//}
	//bool connect(int x, int y) {
	//	x = find(x);
	//	y = find(y);
	//	return x == y;
	//}
	//int minimumEffortPath(vector<vector<int>>& heights) {
	//	if (heights.empty() || heights[0].empty())
	//		return 0;
	//	int cow = heights.size(), row = heights[0].size();
	//	vector<tuple<int, int, int>> vec;
	//	for (int i = 0; i < cow; i++)
	//	{
	//		for (int j = 0; j < row; j++) {
	//			int id = i * row + j;
	//			arr.push_back(id);
	//			size.push_back(1);
	//			if (i > 0) {
	//				vec.emplace_back(id - row, id, abs(heights[i][j] - heights[i - 1][j]));
	//			}
	//			if (j > 0) {
	//				vec.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
	//			}
	//		}
	//	}
	//	sort(vec.begin(), vec.end(), [](const auto&e1, const auto&e2) {
	//		auto&&[x1, y1, v1] = e1;
	//		auto&&[x2, y2, v2] = e2;
	//		return v1 < v2;
	//	});

	//	int ans = 0;
		/*for (const auto[x, y, v] : vec) {
			unionx(x, y);
			if (connect(0, cow*row - 1)) {
				ans = v;
				break;
			}
		}*/
		//return ans;

	//}
}
namespace lt778{
	//778. ˮλ������Ӿ������Ӿ
	/*int swimInWater(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		vector<tuple<int, int, int>> cmap;
		int cow = grid.size(), row = grid[0].size();
		for (int i = 0; i < cow; i++) {
			for (int j = 0; j < row; j++) {
				int id = i * row + j;
				if (i > 0) {
					cmap.emplace_back(id, id - row, max(grid[i][j], grid[i - 1][j]));
				}
				if (j > 0) {
					cmap.emplace_back(id, id - 1, max(grid[i][j], grid[i][j - 1]));
				}
			}
		}
		sort(cmap.begin(), cmap.end(), [](const auto&e1, const auto&e2) {
			auto&&[x1, y1, v1] = e1;
			auto&&[x2, y2, v2] = e2;
			return v1 < v2;
		});
		unionfind f(cow*row);
		for (const auto e : cmap) {
			int x = get<0>(e);
			int y = get<1>(e);
			int val = get<2>(e);
			f.un_ion(x, y);
			if (f.connect(0, cow*row-1))
				return val;
			
		}
		return 0;
	}*/
}
namespace lt839 {
	// 839. �����ַ�����
	bool similar(string&s1,string&s2) {
		int count = 0;
		int index1 = -1, index2 = -1;
		if (s1.size() != s2.size())
			return false;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				if (count == 2)
					return false;
				if (count == 0)
					index1 = i;
				else if (count == 1)
					index2 = i;
				count++;
			}
		}
		if (count == 1)
			return false;

		if (count==0||(count==2&&s1[index1] == s2[index2] && s1[index2] == s2[index1]))
			return true;
		return false;
	}
	int numSimilarGroups(vector<string>& strs) {

		unionfind f(strs.size());
		for (int i = 0; i < strs.size();i++) {
			for (int j = i + 1; j < strs.size(); j++) {
				if (!f.connect(i, j)&&similar(strs[i],strs[j])) {
					f.un_ion(i, j);
				}
			}
		}
		return f.area;
	}
}
namespace lt888 {
	int sumc(vector<int>&arr) {
		int ans = 0;
		for (int i = 0; i < arr.size(); i++) {
			ans += arr[i];
		}
		return ans;
	}
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int suma = sumc(A);
		int sumb = sumc(B);
		int c = sumb - suma;
		c = c / 2;
		map<int, int> cmap;
		for (int i = 0; i < A.size(); i++) {
			cmap[A[i] + c] = A[i];
		}
		vector<int> ans;
		for (int i = 0; i < B.size(); i++) {
			if (cmap.count(B[i]) == 1)
			{

				ans.push_back(cmap[B[i]]);
				ans.push_back(B[i]);
				return ans;
			}
		}
		return ans;
	}
}
namespace lt424 {
	//424. �滻�����ظ��ַ�
	int characterReplacement(string s, int k) {
		vector<int> vec(26, 0);
		int left = 0, maxcount = 0, res = 0;
		for (int i = 0; i < s.size(); i++) {
			vec[s[i] - 'A']++;
			maxcount = max(maxcount, vec[s[i] - 'A']);
			while (i - left + 1 - maxcount > k) {
				vec[s[left] - 'A']--;
				left++;
			}
			res = max(res, i - left + 1);
		}
		return res;
	}
}
namespace lt480 {
	struct movewindom {
		vector<int> minheap;
		vector<int> maxheap;
		int minlen;
		int maxlen;
		int num;

		void init(vector<int> tmpvec, int _num) {
			num = _num;
			minlen = (num + 1) / 2;
			maxlen = num - minlen;
			for (int i = 0; i < (num + 1) / 2; i++) {
				minheap.push_back(tmpvec[i]);
			}
			for (int i = (num + 1) / 2; i < num; i++) {
				maxheap.push_back(tmpvec[i]);
			}
		}

		int with(int cx) {
			int maxmin = minheap[minheap.size() - 1];//��С��������
			int minmax = maxheap[0];//���������С�ġ�
			if (cx <= maxmin) {
				return 0;
			}
			else if (cx > maxmin) {
				return 1;
			}
			return 1;
		}

		int getindex(vector<int> vec, int input) {
			int left = 0, right = vec.size();
			int mid = (left + right) / 2;
			while (left < right) {
				if (vec[mid] < input) {
					left = mid + 1;

				}
				else if (vec[mid] > input) {
					right = mid - 1;
				}
				else  return mid;
				mid = (left + right) / 2;
			}

			return left;
		}
		void insert(int val) {
			int a = with(val);
			if (a == 0) {
				int index = getindex(minheap, val);
				if (minheap[index] < val)
					index++;
				minheap.insert(minheap.begin() + index, val);
			}
			else {
				int index = getindex(maxheap, val);
				maxheap.insert(maxheap.begin() + index, val);
			}
		}
		void erase(int input) {
			int maxmin = minheap[minheap.size() - 1];//��С��������
			int minmax = maxheap[0];//���������С�ġ�
			if (input <= maxmin) {
				int index = getindex(minheap, input);
				minheap.erase(minheap.begin() + index);
			}
			else {
				int index = getindex(maxheap, input);
				maxheap.erase(maxheap.begin() + index);
			}
		}
		void makebalance() {
			int maxsize = maxheap.size(), minsize = minheap.size();
			int distance = maxsize - maxlen;
			if (distance == 0)
				return;
			if (distance > 0) {
				for (int i = 0; i < distance; i++) {
					minheap.push_back(maxheap[0]);
					maxheap.erase(maxheap.begin());
				}
			}
			else {
				for (int i = 0; i < -distance; i++) {
					maxheap.insert(maxheap.begin(), minheap[minheap.size() - 1]);
					minheap.pop_back();
				}
			}
		}
		double makeAns() {
			if (maxlen == minlen)
				return (double(maxheap[0]) + double(minheap[minheap.size() - 1])) / 2;
			else
				return minheap[minheap.size() - 1];
		}
		double find(int input, int output) {
			insert(output);
			erase(input);
			makebalance();
			return makeAns();
		}
	};
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> ans;
		vector<int> vec;
		for (int i = 0; i < k; i++) {
			vec.push_back(nums[i]);
		}
		sort(vec.begin(), vec.end());
		if (k == 1) {

			for (int i = 0; i < nums.size(); i++) {
				ans.push_back(nums[i]);
			}
			return ans;
		}
		if (k % 2 == 0) {
			ans.push_back((double(vec[k / 2]) + (double)vec[(k - 1) / 2]) / 2);
		}
		else ans.push_back(vec[k / 2]);

		movewindom m;
		m.init(vec, k);
		for (int i = k; i < nums.size(); i++) {
			double x = m.find(nums[i - k], nums[i]);
			ans.push_back(x);
		}
		return ans;
	}
	namespace lt643{
		double findMaxAverage(vector<int>& nums, int k) {
			int ans = 0;
			int maxnum = 0;
			for (int i = 0; i < k; i++) {
				ans += nums[i];
			}
			maxnum = ans;
			for (int i = k; i < nums.size(); i++) {
				ans -= nums[i - k];
				ans += nums[i];
				maxnum = max(ans, maxnum);
			}
			return double(maxnum) / k;
		}
	}
}
namespace lt1208 {
	int equalSubstring(string s, string t, int maxCost) {
		vector<int> spend(s.size());
		for (int i = 0; i < s.size(); i++) {
			spend[i] = abs(s[i] - t[i]);
		}
		int left = 0, right = 0;
		int tmp = 0;
		while (right < s.size()) {
			if (maxCost - spend[right] >= 0) {
				
				maxCost -= spend[right];
				right++;
			}
			else {
				if (left == right)
				{
					left++;
					right++;
					continue;
				}
				maxCost += spend[left];
				left++;
			}
			tmp = max(tmp, right - left);
		}
		return tmp;
	}
}
namespace lt1423{
	int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=cardPoints[i];
        }
        int x=cardPoints.size();
        int maxnum=ans;
        int offset=-1;
        do{
            ans-=cardPoints[k+offset];
            ans+=cardPoints[x+offset];
            maxnum=max(maxnum,ans);
            offset--;
        }while(offset+k>=0);
        return maxnum;
    }
}
namespace lt665{
	 bool checkPossibility(vector<int>& nums) {
        int count=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1])
            continue;
            else {
                 count--;
                if(count<0)
                return false;
                if(i>0&&nums[i-1]>nums[i+1])
                {
                    nums[i+1]=nums[i];
                }
               
            }
        }
        return true;
    }
}
namespace lt978{
	  int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1)
        return 1;
        // if(arr.size()==2)
        // return 2;
        int sis=1;
        int maxlen=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]<arr[i+1]){
            arr[i]=1;
            }
            else if(arr[i]>arr[i+1])
            arr[i]=-1;
            else{sis=0; continue;}
            if(i==0){
            maxlen=max(maxlen,1);
            continue;
            }

            if(arr[i]==-arr[i-1])
                sis++;
            else{
                sis=1;
            }
            maxlen=max(1,max(maxlen,sis));
        }
        return maxlen+1;
        
        
    }
}
namespace lt992 {
	struct input
	{
		vector<int > A= {2,1,2,1,2};
		int k = 2;
	};
	int subarraysWithKDistinct(vector<int>& A, int K) {
		int windowsSize = K;
		vector<int> tmp;
		map<int, int> cmap;
		int count = 0;
		for (int i = 0; i < K-1; i++) {
			if (cmap.count(A[i]) == 0) {
				count++;
			}cmap[A[i]]++;
		}
		int ans = 0;
		int ini = count;
		for (int i = K; i <= A.size(); i++) {
			map<int, int>tmp;
			if (++cmap[A[i-1]] == 1)
				ini++;
			count = ini;
			tmp = cmap;
			if (i == A.size()) {
				if (count == K)
					ans++;
				break;
			}
			for (int j = i; j <A.size(); j++) {
				if (count == K) {
					ans++;
				}
				tmp[A[j-i]]--;
				if (tmp[A[j-i]] == 0) {
					count--;
				}
				if (++tmp[A[j]] == 1)
					count++;
				
			}
			if (K == count)
				ans++;
		}

		return ans;
	}

	void test() {
		input c;
		subarraysWithKDistinct(c.A, c.k);
	}

}
namespace lt992d {
	struct input
	{
		vector<int > A = { 1,2,1,3,4 };
		int k = 3;
	};
	int get(vector<int>& A,int K) {
		int left = 0, right = 0, ans = 0;
		int count = 0;
		map<int, int> cmap;
		while (right < A.size()) {
			++cmap[A[right]];
			while (cmap.size() > K) {
				if (--cmap[A[left]] == 0) {
					cmap.erase(A[left]);
				}
				left++;
			}
			ans += right - left;
		}
		return ans;
	}
	int subarraysWithKDistinct(vector<int>& A, int K) {
		return get(A, K) - get(A, K - 1);
	
	}

	void test() {
		input c;
		subarraysWithKDistinct(c.A, c.k);
	}
}
int main() {
	vector<int> nums = { 16807,282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923,7237709,823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612,896544303,474833169,264817709,998097157,817129560,131570933,197493099,404280278,893351816,505795335,954899097,636807826,563613512,101929267,580723810,704877633,358580979,624379149,128236579,784558821,530511967,110010672,551901393,617819336,399125485,156091745,356425228,899894091,585640194,937186357,646035001,25921153,510616708,590357944,771515668,357571490,44788124,927702196,952509530,130060903,942727722,83454666,108728549,685118024,118797801,60806853,571540977,194847408,35308228,158374933,75260298,824938981,595028635,962408013,137623865,997389814,20739063,107554536,635339425,654001669,777724115,269220094,34075629,478446501,864546517,351934195,581030105,557810404,146319451,908194298,500782188,657821123,753799505,102246882,269406752,816731566,884936716,807130337,578354438,892053144,153851501,4844897,616783871,382955828,330111137,227619358,723153177,70982397,147722294,70477904,51621609,606946231,190959745,912844175,341853635,808266298,343098142,456880399,534827968,280090412,195400260,589673557,6441594,889688008,57716395,524325968,14119113,515204530,388471006,681910962,904797942,400285365,322842082,463179852,828530767,832633821,73185695,316824712,260973671,815859901,267248590,51724831,194314738,318153057,111631616,877819790,304555640,213110679,541437335,49077006,996497972,63936098,270649095,428975319,685583454,351345223,272112289,398556760,334948905,724586126,532236123,23129506,836045813,436476770,60935238,936329094,915896220,304987844,34712366,881140534,281725226,901915394,197941363,348318738,152607844,784559590,543436550,290145159,681808623,977764947,750597385,971307217,737195272,755539,399399247,462242385,459413496,951894885,537140623,848682420,12028144,86531968,289335735,755699915,623161625,992663534,43046042,358796011,943454679,771024152,479575244,507977295,119878818,49590396,828087692,621301815,154112991,104740033,222122669,889119397,238489553,882410547,944975825,567121210,866729662,536830211,719533808,517273377,592822761,41000625,902737335,127401868,994977995,140002776,532062767,49997439,433829874,464689331,428540556,968456301,859468872,911300560,168120094,298918984,967113755,124639789,462851407,957828015,678030193,105222769,893015680,944303455,4016855,732267506,784170963,454233502,145586676,329863108,353963249,323602331,1277844,1887638,660760808,561939997,685428651,897054849,465645203,461495731,440796531,796198014,522395419,779636775,203042009,175530180,640687929,351995223,459244054,458588260,174076737,834991545,44747317,34837525,837204200,578134256,486421564,609960597,668306648,683337704,907225550,605925150,416541976,24301412,411938554,111482797,524102504,760348381,293034748,855007065,290659378,379847699,778878209,338725129,121578553,552265483,501650447,218264607,471180773,363045322,494664305,706755176,495170053,616927224,437784630,360280366,121205400,284660444,487495370,684570285,502883016,252193898,637608155,129841133,189515557,262696576,707953178,509658266,307187357,347221711,42227878,847320614,746474819,195795737,586983133,678620591,290623720,135048762,667306633,262976197,112576031,925238588,555860589,795054873,843998877,959637304,21979358,832861200,599777254,168068960,794014915,545293947,442645480,452207730,103669955,564674546,547837107,28841238,989340000,18984926,690545035,988774857,110561113,420250114,862929593,300601360,118498354,322968418,439025357,738342585,163313729,122721015,780776563,32106102,588860917,380786643,172819419,971062967,572547747,83245269,529855395,812423303,490404473,978719103,754711748,47424385,345205658,518163459,520045406,937673930,250739824,614285132,129300973,493959603,600246897,618907920,367603950,9135231,64488480,171620203,350213900,939824520,681462533,603481258,937217003,13618676,255820950,113423934,143558780,168279879,836941832,463482574,828433549,346174542,415306249,523252771,156766310,601915879,752200983,798669970,473392040,666082723,20073650,222902971,118753229,666190318,473917746,118710299,151687230,344185621,554270776,637850124,108668244,26076958,981747696,116666771,958829064,322791560,614056598,790318751,493869940,240764503,462789551,711192801,123427205,119315080,164780418,3559274,838659649,63040413,810783320,51519025,237322012,586901783,458854788,151624117,76424008,263081550,90265324,404319195,754451257,318824511,304835690,270438666,187262410,48760593,766490553,799809565,92190960,556228742,540151403,911254352,746007307,928256141,525244910,633413200,492192799,970343127,566120171,429157787,250334414,450031625,244116641,174619517,13055348,377901842,287114315,927515974,177181445,476211373,805972220,795739911,265509239,90245054,63641305,172556929,61382253,652354189,5815166,537204356,772359304,651659860,73645898,609005592,442901720,463866116,625151580,78098867,495149352,476026939,208178698,401494901,324160811,797716616,482756891,501848671,402331728,356326671,597951661,343077045,102303120,421620240,268317158,38299453,39769627,333685350,962853711,38535563,274629594,550207533,66401727,115307827,948398795,114919531,657737442,140351516,950885006,98478515,4466924,706642601,957627097,596168661,440967103,368034324,799980108,18044936,72002281,547517015,151043710,265963216,130301905,343775973,111767781,225882720,807270791,791481169,910297865,702715827,532329536,238616728,872357125,628320384,796580167,502789949,835500476,8416046,300521576,777568666,158577467,977260520,862627384,516341991,178425210,905333258,14428211,622268744,225419518,464685718,722321934,132666825,436280767,854658689,523449818,528073014,566211825,822102918,173958028,987333029,500078034,708006727,55151240,6933754,571486540,427408396,913090935,401203083,69048048,287846865,709087011,31615252,367553064,301377876,137017237,746232675,628070245,94482710,773470415,791728192,560024710,707454747,722463037,356701299,97368447,88949715,329241693,647259579,132567129,115195164,995333979,473553501,439295525,191110289,502574958,517114033,62211800,562165089,528087670,812535217,430880846,499521038,936509543,8240338,849385936,98603321,954597719,73536496,124791247,67943788,617428359,270425987,767145035,707765235,498383912,152185684,924745989,866683784,120263734,76422667,826500519,862972615,669167045,318665976,142326661,373365825,5182819,1271631,483422903,751072698,162936798,230092639,341914004,29909503,763800679,333748765,88207391,737904107,236264924,207314365,114057121,48114454,205777106,840127450,110051703,448530832,583071032,499932141,48961654,412281977,440942217,742753900,142357289,302173465,978084747,476003622,816289879,258459317,359301516,56564048,484182762,637121029,532649039,166052708,266605903,987502657,996510761,924375752,86561466,785108621,974044557,292006996,554426955,115266930,54021494,346645555,96192221,233429312,586802293,141231427,500142232,432477444,209234791,178402198,311549152,434444856,63273570,227464303,264627439,947712914,324735799,78626766,570591835,67981921,110846043,121122752,688574086,75289719,526439150,230168410,822418623,185044669,282409605,312349943,8437311,657922431,101977992,45139816,396138699,496786971,875180639,45501370,30325836,525679891,147182857,594094833,300383328,601518177,510474410,139217683,14885176,505523489,887972091,283070434,681484711,976226904,463491026,763464891,132610790,494500522,308559364,931706890,539924884,399116813,10341441,9907127,591316179,844185784,598994537,45329870,88387561,264032581,894374165,508545802,937357732,231367332,645347854,214459759,947609847,739972377,637940462,626979010,726943819,710298150,119413377,230900941,42143836,434826720,245832299,92396112,856734759,56219956,788974390,728536152,348330048,342695014,123959044,320514918,5240150,817350101,897741295,910819821,885295731,398644501,662128245,129154961,748946057,927703510,974593928,935350805,653662173,366782137,229309669,67439096,725004503,121447421,850318675,595278518,867224300,260276489,835740262,743532054,128868263,18358643,902024889,245245250,608776735,891469415,726031364,407052494,595850963,543867758,887985652,156485092,524957316,887766714,771761420,192958060,345807450,895063368,207078741,448891847,208199196,746004787,885902501,652188234,364093128,925270571,886377448,44687875,242817253,810641871,821669329,476562293,261433719,164973471,307738820,25725764,521681079,511142630,839594410,95688080,350266113,462863342,951398138,778248382,845146044,705698828,920998393,157863575,70800980,39109000,967945596,73005947,590767370,3266087,644506543,313952733,236262852,172490261,88376824,876554400,511982380,68370778,789871857,425373423,278059498,421567014,728252845,236261662,945468509,257726610,929596849,790709218,821019290,288775055,922285743,319518555,439236385,137606534,499086275,864877321,823811151,759921226,703775251,803694459,20632783,30316714,372366437,388337879,384907698,715914100,810383137,768094285,836445878,717918284,489470342,311164915,626045960,432063067,834735140,675810707,309543566,293320728,12000562,977466363,820241969,109242890,739712623,567222278,624917313,790245761,267127010,362834840,104576978,983646000,809207394,334734507,623187656,430166551,24761786,706993431,204554544,619880739,892408776,688507584,105074252,544374108,808275514,497991454,998595019,801783028,107466671,158592370,434756663,215867947,785684024,907424543,802916854,629306008,389114981,767780552,5986288,265768163,792508359,994411019,348255379,28195356,871419461,108408487,955308353,279743899,606985788,855794244,281369880,224582466,428738283,789665274,248300236,414318909,108898567,40621834,978847939,418069684,78169651,123289549,598709266,545747467,268000110,797619589,792486327,417097773,568625581,380889295,750607936,148637874,426245435,694558231,866566972,949983028,971319798,594139070,43874587,251766297,893369089,796102646,67029090,714958111,129966612,150957463,756872112,996923781,423551951,522329230
};
	using lt992d::test;
		//using lt480::medianSlidingWindow;
	test();

		return 0;
//	medianSlidingWindow(nums, 2);
}