#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, p, q;
    cin >> n >> p >> q;

    // Read egos and keep their original indices
    vector<pair<ll,int>> v(n); // {ego, original_index}
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }

    // Read queries (1-based indices)
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
        --queries[i]; // convert to 0-based original index
    }

    // Sort by ego value
    sort(v.begin(), v.end()); 
    // Build arrays: A = sorted egos, pos[orig] = position in sorted array
    vector<ll> A(n);
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        A[i] = v[i].first;
        pos[v[i].second] = i;
    }

    // Two-pointer to compute r[L]: maximal R s.t. A[R] - A[L] <= p
    vector<int> r(n);
    int R = 0;
    for (int L = 0; L < n; ++L) {
        if (R < L) R = L;
        while (R + 1 < n && A[R+1] - A[L] <= p) ++R;
        r[L] = R;
        // next L: R does not need to move left because r[L] is non-decreasing
    }

    // len[L] = length of maximal interval that starts at L
    vector<int> len(n);
    for (int i = 0; i < n; ++i) len[i] = r[i] - i + 1;

    // For each sorted position i, we want the maximum len[L] among intervals [L, r[L]] that cover i.
    // Process i = 0..n-1, maintain a max-heap of pairs (len[L], r[L]) for L <= i.
    priority_queue<pair<int,int>> pq; // sorts by len desc, then r desc
    vector<int> ans_sorted(n, 1);

    for (int i = 0; i < n; ++i) {
        // push the interval that starts at L = i
        pq.push({len[i], r[i]});
        // remove intervals that no longer cover position i (their r < i)
        while (!pq.empty() && pq.top().second < i) pq.pop();
        // top of heap now has the maximum len among intervals covering i
        if (!pq.empty()) ans_sorted[i] = pq.top().first;
        else ans_sorted[i] = 1; // fallback (shouldn't happen because interval L=i covers i)
    }

    // Map answers back to original indices and answer queries
    // For a query asking original index X, find pos[X] in sorted array and output ans_sorted[pos[X]]
    for (int qi = 0; qi < q; ++qi) {
        int orig = queries[qi];
        int sorted_pos = pos[orig];
        cout << ans_sorted[sorted_pos] << '\n';
    }

    return 0;
}

