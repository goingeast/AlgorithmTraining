// In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

// When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

// Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

 

// Example 1:

// Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
// Output: [null,0,9,4,2,null,5]
// Explanation:
// ExamRoom(10) -> null
// seat() -> 0, no one is in the room, then the student sits at seat number 0.
// seat() -> 9, the student sits at the last seat number 9.
// seat() -> 4, the student sits at the last seat number 4.
// seat() -> 2, the student sits at the last seat number 2.
// leave(4) -> null
// seat() -> 5, the student sits at the last seat number 5.
class Inte{
  public:
    Inte(int x, int y, int N):x(x), y(y), N(N){
        if(x == -1){
            dist = y;
        }else if(y == N){
            dist = N - 1 - x;
        }else {
            dist = (y-x)/2;
        }
    }
    
    bool operator< (const Inte& a) const{
        return dist > a.dist || ((dist == a.dist) && x < a.x);
    }
    
    int x;
    int y;
    private:
    int N;
    int dist;
};

class ExamRoom {
public:
    ExamRoom(int N):N(N) {
        st.emplace(-1, N, N);
    }
    
    int seat() {
        int seat = 0;
        auto a = st.begin();
       
        if(a->x == -1) seat = 0;
        else if(a->y == N) seat = N -1;
        else seat = (a->x + a->y)/2;
        
        auto prev = st.emplace(a->x, seat, N);
        auto next = st.emplace(seat, a->y, N);

        mp[seat] = {prev.first ,next.first};
        
        mp[a->x].second = st.find({a->x, seat, N});
        mp[a->y].first = st.find({seat, a->y, N});
        
        st.erase(a);

        return seat;
    }
    
    void leave(int p) {
        int s = mp[p].first->x;
        int e = mp[p].second->y;
        st.erase(mp[p].first);
        st.erase(mp[p].second);
        
        auto it = st.emplace(s, e, N);
        mp.erase(p);
        
        mp[s].second = it.first;
        mp[e].first = it.first;
        
        
    }
    private:
    int N;
    unordered_map<int, pair<set<Inte>::iterator,set<Inte>::iterator> > mp;
    set<Inte> st;
};